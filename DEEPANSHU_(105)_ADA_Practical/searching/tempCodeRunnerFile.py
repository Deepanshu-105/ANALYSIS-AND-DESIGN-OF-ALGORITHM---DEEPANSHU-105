import matplotlib.pyplot as plt

# Sample data
x = [10, 50, 100,500,1000,3000,5000,6000,7000,8000,9000,10000]
y = [0.000000,0.000000,0.000000,0.000000,0.000001,0.000000,0.000000,0.000000,0.000001,0.000000,0.000001,0.000000]

# Create the plot
plt.plot(x, y, marker='o', linestyle='-', color='c', label='Prime Numbers')

# Add labels and title
plt.xlabel('NUMBER OF ELEMENTS IN AN ARRAY : n')
plt.ylabel('Time taken in sec')
plt.title('Simple Line Graph')
plt.legend()

# Show the plot
plt.grid(True)
plt.show()
