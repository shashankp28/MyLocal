import math

class Point:
    def __init__(self, coordinate, tra):
        self.x = coordinate[0]
        self.y = coordinate[1]
        self.trainer = tra
            
    def get_vertical_reflections(self, y_dimension, maximum):
        reflections = [self]
        for i in range(1, maximum):
            new_y = 2*((i+1)//2)*y_dimension + ((-1)**(i))*self.y
            new_point = Point((self.x, new_y), self.trainer)
            reflections.append(new_point)
        return reflections
    
    def get_horizontal_reflections(self, x_dimension, maximum):
        reflections = [self]
        for i in range(1, maximum):
            new_x = 2*((i+1)//2)*x_dimension + ((-1)**(i))*self.x
            new_point = Point((new_x, self.y), self.trainer)
            reflections.append(new_point)
        return reflections
    
    def euc_distance(self, point):
        return ((self.x-point.x)**2+(self.y - point.y)**2)**0.5
    
    def radians(self, point):
        return math.atan2(point.y-self.y, point.x-self.x)
    
    def single_reflection(self, unit):
        return Point((self.x*unit[0], self.y*unit[1]), self.trainer)

    def __eq__(self, point):
        return self.x==point.x and self.y==point.y

def reflect_across_quadrants(quadrant_1_points):
    all_reflections = []
    for point in quadrant_1_points:
        unit_reflectors = [[1, 1], [-1, 1], [-1, -1], [1, -1]]
        for unit_reflector in unit_reflectors:
            reflected_point = point.single_reflection(unit_reflector)
            all_reflections.append(reflected_point)
    return all_reflections

def solution(dimensions, your_position, trainer_position, distance):
    no_x_reflctions = int(math.ceil((your_position[0]+distance)/dimensions[0])) + 1
    no_y_reflctions = int(math.ceil((your_position[1]+distance)/dimensions[1])) + 1
    
    all_reflected_points_quadrant_1 = []
    
    root_point_you = Point(your_position, False)
    root_point_trainer = Point(trainer_position, True)
    
    vertical_reflection_zip_trainer_you = zip(root_point_trainer.get_vertical_reflections(dimensions[1], no_y_reflctions), 
                                    root_point_you.get_vertical_reflections(dimensions[1], no_y_reflctions))
    
    for vertically_reflected_point_trainer, vertically_reflected_point_you in vertical_reflection_zip_trainer_you:
        all_reflected_points_quadrant_1 += vertically_reflected_point_trainer.get_horizontal_reflections(dimensions[0], no_x_reflctions)
        all_reflected_points_quadrant_1 += vertically_reflected_point_you.get_horizontal_reflections(dimensions[0], no_x_reflctions)
    
    all_reflected_points = reflect_across_quadrants(all_reflected_points_quadrant_1)
    
    
    angle_min_distance_to_trainer = {}
    for point in all_reflected_points:
        if root_point_you.euc_distance(point)>distance or point==root_point_you:
            continue
        
        if point.trainer:
            angle = root_point_you.radians(point)
            min_distance_for_angle = angle_min_distance_to_trainer.get(angle)
            if min_distance_for_angle is None:
                angle_min_distance_to_trainer[angle] = root_point_you.euc_distance(point)
            else:
                angle_min_distance_to_trainer[angle] = min(min_distance_for_angle, root_point_you.euc_distance(point))
    
    
    for point in all_reflected_points:
        if point==root_point_you:
            continue
        
        if not point.trainer:
            angle = root_point_you.radians(point)
            distance_from_you = root_point_you.euc_distance(point)
            min_distance_for_angle = angle_min_distance_to_trainer.get(angle)
            if min_distance_for_angle is None:
                continue
            if min_distance_for_angle>=distance_from_you:
                del angle_min_distance_to_trainer[angle]
    
    return len(angle_min_distance_to_trainer)


print solution([3,2], [1,1], [2,1], 4)