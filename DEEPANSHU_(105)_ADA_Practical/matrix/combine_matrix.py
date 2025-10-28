import matplotlib.pyplot as plt

# Sample data
x = ['4x4','8X8','16X16','32X32','64X64','128X128','256X256','512X512','1024X1024']
y1 = [0.000000,0.000000,0.000000,0.000000,0.000001,0.000008,0.000089,0.000483,0.004761]
y2 =[0.000000,0.000001,0.000002,0.000019,0.000101,0.000734,0.005510,0.050319,0.447733]
y3=[0.000000,0.000001,0.000003,0.000014,0.000080,0.000551,0.003344,0.024346,0.358179]
# Create the plot
plt.plot(x, y1, marker='o', linestyle='-', color='c', label='ITERATIVE APPROACH')
plt.plot(x, y2, marker='o', linestyle='-', color='y', label='DIVIDE AND CONQUER APPROACH')
plt.plot(x, y3, marker='o', linestyle='-', color='b', label="STRASSEN'S APPROACH")

# Add labels and title
plt.xlabel('MATRIX SIZES : N*N')
plt.ylabel('TIME TAKEN TO COMPUTE')
plt.title('COMPARISION OF TIME COMPLEXITY OF MATRIX MULTIPLICATION')
plt.legend()

# Show the plot
plt.show()

