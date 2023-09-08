import random
import pandas as pd

numbers = [35, 56, 81, 24, 17, 54, 12, 32, 6, 55, 30, 33, 23, 48, 27, 13, 34, 8, 25, 70, 44, 64, 50,
           36, 14, 39, 2, 28, 60, 43, 49, 29, 45, 11, 31, 18, 10, 9, 53, 5, 16, 4, 15, 66, 7, 58, 63, 42, 1, 3]
numbers.sort()
all_numbers = list(range(1, 100))

# Filter out the excluded numbers
remaining_numbers = [num for num in all_numbers if num not in numbers]

def generate_matrix():
    visited = []
    matrix = []
    for _ in range(5):
        row = []
        for _ in range(5):
            if (random.random() < 0.85):
                number = random.choice(numbers)
                while (number in visited): 
                    number = random.choice(numbers)
                
                visited.append(number)
                    
            else:
                number = random.choice(remaining_numbers)
                while (number in visited): 
                    number = random.choice(remaining_numbers)
                
                visited.append(number)
                
            row.append(number)
        matrix.append(row)
    visited.clear()
    return matrix


matrices = []
for i in range(25):
    matrix = generate_matrix()
    matrices.append(matrix)

# Create a Pandas DataFrame for each matrix
dfs = []
for i, matrix in enumerate(matrices):
    df = pd.DataFrame(matrix)
    dfs.append(df)

# Create a writer object for Excel
writer = pd.ExcelWriter('matrices.xlsx', engine='xlsxwriter')

# Write each DataFrame to a separate sheet in the Excel file
for i, df in enumerate(dfs):
    df.to_excel(writer, sheet_name=f'Matrix_{i+1}', index=True)

# Save the Excel file
writer._save()

# def print_matrix(matrix):
#     for row in matrix:
#         print(row)


# # Generate 25 matrices
# for i in range(25):
#     print(f"Matrix {i+1}:")
#     matrix = generate_matrix()
#     print_matrix(matrix)
#     print()
