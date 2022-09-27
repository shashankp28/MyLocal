def greedy(s):
    file = open(s, 'r+')
    clients = int(file.readline())
    likes = []
    dislikes = []
    ingredients = {}
    counter = []
    for i in range(clients):
        temp_likes = list(file.readline().strip("\n").split(" "))
        temp_dislikes = list(file.readline().strip("\n").split(" "))
        likes.append(temp_likes)
        dislikes.append(temp_dislikes)
    
    for i in range(clients):
        num_dislikes = int(dislikes[i][0])
        num_likes = int(likes[i][0])
        temp_num_dislikes = 0
        if(num_dislikes >= 1):
            for j in range(1,num_dislikes+1):
                if(dislikes[i][j] not in ingredients):
                    temp_num_dislikes+=1
        if (temp_num_dislikes == num_dislikes):
            for k in range(1,num_likes+1):
                ingredients[likes[i][k]] = 1
        answer = []
        answer_count = 0
        output = open('output_E.txt', 'w')
    for key in ingredients:
        if ingredients[key] > 0:
            answer.append(key)
            answer_count+=1
    answer.insert(0, answer_count)  
    for item in answer:
        output.write(str(item) + " ")
    return answer