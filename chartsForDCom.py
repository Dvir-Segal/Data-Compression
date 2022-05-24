import matplotlib.pyplot as plt



# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    # ! /usr/bin/env/ python3

    # with open("1mb.txt", "wb") as out:
    #     out.seek((1024 * 1024) - 1)
    #     out.write(b'\0')

    # Tasks = [44,956]
    Tasks = [79798,20202]

    my_labels = 'New Transform is better','Equals'
    plt.pie(Tasks,labels=my_labels,autopct='%1.1f%%')
    plt.title('Distribution for 100K lotteries - series length 2^3')
    plt.axis('equal')
    plt.show()
