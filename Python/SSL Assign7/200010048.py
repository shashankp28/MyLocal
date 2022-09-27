import random as ran
import numpy as num
import matplotlib.pyplot as plt
state = ["Andhra_Pradesh","Arunachal_Pradesh","Assam","Bihar","Chhattisgarh","Goa","Gujarat","Haryana",
             "Himachal_Pradesh","Jharkhand","Karnataka","Kerala","Madhya_Pradesh","Maharashtra",
             "Manipur","Meghalaya","Mizoram","Nagaland","Odisha","Punjab","Rajasthan","Sikkim","Tamil_Nadu",
             "Telangana","Tripura","Uttarakhand","Uttar Pradesh","West_Bengal"]
#####################################################
#1. Create randGen() function:
def randGen():
    f = open("dataset.txt", "w+")
    for i in range(10000):
        f.write(str(ran.randint(1, 100))+', ')
        f.write("male, " if ran.randint(1, 2)==1 else "female, ")
        f.write(state[ran.randint(0, 27)]+', ')
        f.write(str(ran.randint(6000000000, 9999999999))+', ')
        f.write(str(ran.gauss(160, 10))+', ')
        f.write(str(ran.gauss(70, 5)) + '\n')
    f.close()
#####################################################

#####################################################
#2. Create Person Class:
class Person:
    def __init__(self, a, g, s, p, h, w):
        self.Age = a
        self.Gender = g
        self.State = s
        self.Phone_number = p
        self.Height = h
        self.Weight = w
#####################################################

if __name__ == "__main__":
    randGen()

#####################################################
#3. Generate 10000 instances:
    instance = []
    f = open("dataset.txt", "r")
    for i in f:
        t = i.strip().split(', ')
        instance.append(Person(int(t[0]), t[1], t[2], int(t[3]), float(t[4]), float(t[5])))
    f.close()
#####################################################

#####################################################
#4. Average height and weight:
    f = open("dataset.txt", "a+")
    h = [instance[i].Height for i in range(10000)]
    w = [instance[i].Weight for i in range(10000)]
    f.write("Average Height = " + str(num.mean(h)) + '\n')
    f.write("Average Weight = " + str(num.mean(w)) + '\n')
    f.close()
#####################################################
#####################################################
#4. Plots:
    #---------------------------------------------------------------------------------------------------#
    #A. Height Histogram:
    fig, ax = plt.subplots(1, 2, figsize=(16, 9))
    fig.suptitle('Heights of Male and Female population', fontsize=16)
    ax[0].hist([instance[i].Height for i in range(10000) if instance[i].Gender=="male"], color="blue", bins=200, rwidth=0.5)
    ax[1].hist([instance[i].Height for i in range(10000) if instance[i].Gender=="female"], color="red", bins=200, rwidth=0.5)
    ax[0].title.set_text('Male Height')
    ax[1].title.set_text('Female Height')
    ax[0].set_xlabel('Male Height')
    ax[0].set_ylabel('No. of Males')
    ax[1].set_ylabel('No. of Females')
    ax[1].set_xlabel('Male Height')
    plt.savefig('height.jpg')
    # ---------------------------------------------------------------------------------------------------#
    # B. Height Histogram:
    fig, ax = plt.subplots(1, 2, figsize=(16, 9))
    fig.suptitle('Weights of Male and Female population', fontsize=16)
    ax[0].hist([instance[i].Weight for i in range(10000) if instance[i].Gender == "male"], color="blue", bins=200, rwidth=0.5)
    ax[1].hist([instance[i].Weight for i in range(10000) if instance[i].Gender == "female"], color="red", bins=200, rwidth=0.5)
    ax[0].title.set_text('Male Weight')
    ax[1].title.set_text('Female Weight')
    ax[0].set_xlabel('Male Weight')
    ax[0].set_ylabel('No. of Males')
    ax[1].set_ylabel('No. of Females')
    ax[1].set_xlabel('Male Weights')
    plt.savefig('weight.jpg')
    # ---------------------------------------------------------------------------------------------------#
    # C. Gender Pie-Chart:
    fig1, ax1 = plt.subplots(figsize=(16, 9))
    gen = ["Male", "Female"]
    count = [0, 0]
    for i in range(10000):
        if instance[i].Gender=="male":
            count[0] += 1
        else:
            count[1]+=1
    ax1.title.set_text('Gender Distribution of the population')
    ax1.pie(count, labels = gen, shadow=True, startangle=90, autopct='%1.2f%%')
    plt.savefig('gender.jpg')
    # ---------------------------------------------------------------------------------------------------#
    # D. Gender Pie-Chart:
    fig1, ax1 = plt.subplots(figsize=(16, 9))
    ph = [6, 7, 8, 9]
    count = [0, 0, 0, 0]
    for i in range(10000): count[int(list(str(instance[i].Phone_number))[0])-6]+=1
    ax1.title.set_text('Distribution of first digit of phone numbers')
    ax1.pie(count, labels=ph, shadow=True, startangle=90, autopct='%1.2f%%')
    plt.savefig('phone.jpg')
    # ---------------------------------------------------------------------------------------------------#
    # E. Age Line Plot:
    fig, ax = plt.subplots(figsize=(16, 9))
    x = range(1, 101)
    y1 = [instance[i].Age for i in range(10000) if instance[i].Gender == "male"]
    y_1 = [y1.count(1)]
    for i in range(2, 101): y_1.append(y_1[i-2] + y1.count(i))
    y2 = [instance[i].Age for i in range(10000) if instance[i].Gender == "female"]
    y_2 = [y2.count(1)]
    for i in range(2, 101): y_2.append(y_2[i - 2] + y2.count(i))
    ax.plot(x, y_1)
    ax.plot(x, y_2)
    ax.legend(["Male", "Female"], loc ="lower right")
    ax.set_xlabel('Age')
    ax.set_ylabel('Cumulative Count')
    ax.title.set_text('Cumulative Distribution of age among Male and Female')
    plt.savefig('age.jpg')
    # ---------------------------------------------------------------------------------------------------#
    # F. State Bar graph:
    fig, ax = plt.subplots(figsize=(16, 9))
    total = [instance[i].State for i in range(10000)]
    state_count = [total.count(i) for i in state]
    ax.bar(state, state_count)
    fig.autofmt_xdate()
    ax.set_xlabel("Count")
    ax.set_ylabel("States")
    ax.title.set_text("Plot of No. of People from different states")
    plt.savefig('state.jpg')
plt.show()
#####################################################



