import random

def generate_test_cases(num_cases, colors):
    """Generate test cases with randomly selected colors."""
    test_cases = []
    for _ in range(num_cases):
        color = random.choice(colors)
        test_cases.append(color)
    return test_cases

def save_to_file(filename, test_cases):
    """Save the test cases to a file."""
    with open(filename, "w") as file:
        for i, color in enumerate(test_cases, start=1):
            file.write(f"{color}\n")

# Define the array of Indian-related colors
indian_colors = [
    "saffron",  "blue", "green", 
    "lotus_pink", "indigo", "sandalwood", "ruby_red", 
    "white", "golden"
]

# Take user input for the number of test cases
try:
    num_cases = int(input("Enter the number of test cases to generate: "))
    if num_cases <= 0:
        print("Please enter a positive number.")
    else:
        # Generate test cases and save to a file
        test_cases = generate_test_cases(num_cases, indian_colors)
        save_to_file("output.txt", test_cases)
        print(f"{num_cases} test cases have been saved to output.txt.")
except ValueError:
    print("Invalid input. Please enter a valid number.")
