import random

# Function to generate a list of passwords based on given lengths
def password_generator(password_lengths):
    # Define the characters that can be used in the password
    data_string = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789@$^&**_"
    
    # Initialize an empty list to store the generated passwords
    passwords_list = []
    
    # Iterate over each password length
    for length in password_lengths:
        # Initialize an empty string to build the password
        password = ''
        
        # Generate the password by randomly selecting characters from the data string
        for _ in range(length):
            # Get a random index within the bounds of the data string
            next_index = random.randrange(len(data_string))
            
            # Append the character at the random index to the password
            password += data_string[next_index]
        
        # Add the generated password to the list
        passwords_list.append(password)
    
    # Return the list of generated passwords
    return passwords_list

# Function to get a valid integer input from the user
def get_valid_integer(prompt):
    while True:
        try:
            value = int(input(prompt))
            if value <= 0:
                print("Please enter a positive integer.")
            else:
                return value
        except ValueError:
            print("Invalid input. Please enter a valid integer.")

# Main function to execute the program
def main():
    # Prompt the user to enter the number of passwords to generate
    num_passwords = get_valid_integer("Enter the number of passwords to generate: ")
    
    # Print a message to indicate that password generation is in progress
    print(f"Generating {num_passwords} passwords...")
    
    # Initialize an empty list to store the password lengths
    password_lengths = []
    
    # Iterate over each password to generate
    for i in range(num_passwords):
        # Prompt the user to enter the length of the current password
        print(f"Enter the length of password {i + 1}: ")
        print("Note: Minimum length of password is 6!")
        
        # Get the password length from the user and ensure it's at least 6
        length = get_valid_integer("Enter the length: ")
        if length < 6:
            print("Password length must be at least 6. Using 6 as the length.")
            length = 6
        
        # Add the password length to the list
        password_lengths.append(length)
    
    # Generate the passwords using the provided lengths
    passwords = password_generator(password_lengths)
    
    # Print each generated password
    for i, password in enumerate(passwords):
        print(f"Password {i + 1}: {password}")

# Execute the main function
if __name__ == "__main__":
    main()
