def find_lines_with_text(file_path, text):
    try:
        with open(file_path, 'r') as file:
            lines = file.readlines()

        found = False
        for line in lines:
            if text in line:
                print(line.strip())
                found = True

        if not found:
            print(f"No lines found containing '{text}'.")

    except FileNotFoundError:
        print(f"File not found: {file_path}")
    except Exception as e:
        print(f"An error occurred: {e}")


def main():
    file_path = input("Enter the path of the text file: ")

    while True:
        text = input("\nEnter a word or a sentence to search for (or 'exit' to quit): ")
        if text.lower() == 'exit':
            break
        find_lines_with_text(file_path, text)


if __name__ == "__main__":
    main()
