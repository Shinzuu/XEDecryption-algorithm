def importFile(file_name):
    try:
        # Open the file in read mode ("r")
        with open(file_name, "r") as file:
            # Read the content of the file
            content = file.read()
            return content
    except FileNotFoundError:
        print(f"Error: The file {file_name} was not found.")
    except Exception as e:
        print(f"An error occurred: {e}")
        return None

# Specify the file name with its path
file_name = "your_file.txt"

# Assign the imported content to a variable
imported_string = importFile(file_name)

# Check if the imported content is not None (i.e., no errors occurred)
if imported_string is not None:
    print("Imported file content:")
    print(imported_string)
