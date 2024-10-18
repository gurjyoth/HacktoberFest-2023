# Contributed by: 
# Name: Abhijai Rajawat
# University: VIT, Vellore

# Problem Statement:
# Write a Python program to convert Celsius to Fahrenheit by taking input from the user.

# Function to convert Celsius to Fahrenheit
def convert_celsius_to_fahrenheit(celsius):
    # Formula to convert Celsius to Fahrenheit
    fahrenheit = (celsius * 9 / 5) + 32
    return fahrenheit

# Main function to execute the program
def main():
    # Prompt the user to enter the temperature in Celsius
    celsius_input = input("Enter the temperature in Celsius: ")
    
    try:
        # Convert the input to a float
        celsius = float(celsius_input)
        
        # Call the conversion function
        fahrenheit = convert_celsius_to_fahrenheit(celsius)
        
        # Display the result in a formatted string
        print(f"{celsius:.2f} degrees Celsius is equal to {fahrenheit:.2f} degrees Fahrenheit.")
    
    except ValueError:
        # Handle the case where the input is not a valid number
        print("Please enter a valid number for the temperature in Celsius.")

# Execute the main function
if __name__ == "__main__":
    main()
