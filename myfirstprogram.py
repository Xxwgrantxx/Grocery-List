import re
import string
import collections
#!/usr/bin/python

def printTodaysPurchases(): #this definition prints text from a list when user chooses
    document = input("Enter file to open: ")   #for this i am using Grocerylist.txt
# Open the file in read mode                    #option 1 
    text = open(document, "r")

    # Create an empty dictionary
    d = dict()
  
# Loop through each line of the file
    for line in text:
    # Remove the leading spaces and newline character
        line = line.strip()
  
    # Convert the characters in line to 
    # lowercase to avoid case mismatch
        line = line.lower()
  
    # Split the line into words
        words = line.split(" ")
  
    # Iterate over each word in line
        for word in words:
        # Check if the word is already in dictionary
            if word in d:
            # Increment count of word by 1
                d[word] = d[word] + 1
            else:
            # Add the word to dictionary with count 1
                d[word] = 1
  
# Print the contents of dictionary
    print("Items and amount purchased: ")
    for key in list(d.keys()):     
        print(key, ":", d[key])

    print('\n' + "List complete")               #user is notified that all information is loaded

    text.close() #close file to allow other files access


def PrintMe(v):                     #(v) stores itemName from C++ option 2
# Open the file in read mode
    text = open("Grocerylist.txt", "r")

    # Create an empty dictionary
    d = dict()
  
# Loop through each line of the file
    for line in text:
    # Remove the leading spaces and newline character
        line = line.strip()
  
    # Convert the characters in line to 
    # lowercase to avoid case mismatch
        line = line.lower()
  
    # Split the line into words
        words = line.split(" ")
  
    # Iterate over each word in line
        for word in words:
        # Check if the word is already in dictionary
            if word in d:
            # Increment count of word by 1
                d[word] = d[word] + 1
            else:
            # Add the word to dictionary with count 1
                d[word] = 1
  
    text.close()    #close file to allow other files access
# Print the contents of dictionary
    if v in d:
        return d.get(v, 'Not Found')        #if v is in the dictionary, quantity is sent to C++
    else:
        return 0                            #if v is not in dictionary, 0 is returned to C++
    

def printhistogram():
    with open("frequency.dat", "w") as file:        #here python creates a file to write new information to
# Open the file in read mode
        text = open("Grocerylist.txt", "r")         

    # Create an empty dictionary
        d = dict()
  
# Loop through each line of the file
        for line in text:
    # Remove the leading spaces and newline character
            line = line.strip()
  
    # Convert the characters in line to 
    # lowercase to avoid case mismatch
            line = line.lower()
  
    # Split the line into words
            words = line.split(" ")
  
    # Iterate over each word in line
            for word in words:
        # Check if the word is already in dictionary
                if word in d:
            # Increment count of word by 1
                    d[word] = d[word] + 1
                else:
            # Add the word to dictionary with count 1
                    d[word] = 1
  
# Information is written to file that was created
        for key in list(d.keys()):     
            file.write(key + " " + str(d[key]) + '\n')
        text.close() #file opened in read mode is closed to be useable elsewhere
