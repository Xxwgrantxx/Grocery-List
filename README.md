# Grocery List
The goal of this project was to integrate Python and C++ to read data from a grocery list, display item quantities, and generate a histogram. To ensure modularity and ease of debugging, I implemented separate functions for each menu option, allowing for straightforward troubleshooting if errors arise. If an issue occurs in a specific option, I can quickly navigate to its corresponding function for adjustments.

For options 2 and 3, I hardcoded the list being processed, which limits portability and adaptability. Ideally, the list should be dynamically sourced, similar to option 1, which prompts the user for input. However, due to persistent issues with handling user input in this function, I opted for a hardcoded approach for now, with plans to refine it in future iterations.

One of the most challenging aspects was calling Python functions from C++, as it required navigating interoperability complexities. I relied on YouTube tutorials and online resources to resolve issues and refine implementation strategies. Despite these challenges, the program remains highly maintainable thanks to its structured function-based design, allowing for efficient bug tracking and fixes based on user interactions.

Additionally, I prioritized code readability, incorporating frequent comments and ample whitespace to ensure clarity. While the current implementation serves its purpose, improving adaptability—specifically in how the list is sourced—remains a key area for future enhancements. Once I resolve the issues affecting option 1, I will update the program to support a more flexible and scalable approach


