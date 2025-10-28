import matplotlib.pyplot as plt

# Sample data
x = [10, 50, 100,500,1000,3000,5000,6000,7000,8000,9000,10000]
y = [0.000000,0.000001,0.000004,0.000004,0.000002,0.000001,0.000002,0.000009,0.000010,0.000002,0.000002,0.000004]

# Create the plot
plt.plot(x, y, marker='o', linestyle='-', color='b', label='Prime Numbers')

# Add labels and title
plt.xlabel('NUMBER OF ELEMENTS IN AN ARRAY : n')
plt.ylabel('TIME TAKEN')
plt.title('LINEAR SEARCH GROWTH GRAPH')
plt.legend()

# Show the plot
plt.grid(True)
plt.show()




