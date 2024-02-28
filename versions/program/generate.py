def generate_bible_chapters_format_to_file():
    # Define the book name
    book_name = "Job"
    # Assuming the number of verses in the first 10 chapters of Job
    chapter_verse_counts = {
        1: 22,  # Chapter 1 has 22 verses
        2: 13,  # Chapter 2 has 13 verses, and so on...
        3: 26,
        4: 21,
        5: 27,
        6: 30,
        7: 21,
        8: 22,
        9: 35,
        10: 22,
    }
    
    # Open a file to write
    with open('formatted_job_verses.txt', 'w') as file:
        # Generate and write the formatted listing to the file
        for chapter, verse_count in chapter_verse_counts.items():
            for verse in range(1, verse_count + 1):
                formatted_line = f"{book_name:<15}{chapter:>3}:{verse:>3}  \n"
                file.write(formatted_line)

# Call the function to generate the format and write to a file
generate_bible_chapters_format_to_file()
