#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <string>
using namespace std;

struct trie{
    // to store the character
    char d;
    // to store how many words begin from that letter
    int count;
    // variable to determine the end of our word stored
    int end;
    // each node can have at max 26 children
    trie* child[26];
};
// our root node
trie* root;

// function to return a new trie node which is to be inserted
trie* newNode(char x){
    // initialize our new node with the appropriate data
    trie* newnode = new trie;
    newnode->d = x;
    newnode->count = 1;
    newnode->end = 0;
    // assign NULL to all child pointers
    for(int i = 0; i < 26; i++){
        newnode->child[i] = NULL;
    }
    return newnode;
}

// function to return count of a trie node
int getCount(trie* x){
    return x->count;
}

// function to return end of a trie node
int getEnd(trie* x){
    return x->end;
}

char getData(trie* x){
    return (x->d);
}

// function to add a word into our trie data structure
void add(string x){
    // variable for loop iteration
    int legnth = x.length();
    // var to determine where we are to add the characters
    int index;
    // var to move through out the trie
    trie* temp = new trie;
    temp = root;

    // inserting all the characters of our word into the trie
    for(int i = 0; i < legnth; i++){
        // finding where the character is to be inserted
        index = x[i] - static_cast<int>('a');
        // if there is no such alphabet already then add it
        if(temp->child[index] == NULL){
            temp->child[index] = newNode(x[i]);
        }
        // increment the number of words that have those letters
        temp->child[index]->count = getCount(temp->child[index]) + 1;
        // move onto the next trie node
        temp = temp->child[index];
    }
    // increment the number of words ending at the specific trie node by 1
    temp->end = getEnd(temp) + 1;
}

// function to search the trie for a word
bool searchTrie(string x){
    trie* temp = new trie;
    temp = root;
    int legnth = x.length();
    int index;
    // traversing the word till we reach the end character
    for(int i = 0; i < legnth; i++){
        index = x[i] - static_cast<int>('a');
        if(temp->child[index] == NULL){
            return false;
        }
        temp = temp->child[index];
    }
    // if the word ends at the last character return true
    // else return false
    if(temp->end > 0){
        return true;
    }
    else{
        return false;
    }
}

// function to add words into the trie
void add_words(){
    add("the"); add("us"); add("most"); add("give"); add("day"); add("any"); add("these");
    add("tomorrow"); add("want"); add("new"); add("because"); add("bee"); add("even");
    add("from"); add("well"); add("way"); add("well"); add("work"); add("our");
    add("they"); add("how"); add("first"); add("two"); add("use"); add("after"); add("back");
    add("if"); add("also"); add("think"); add("over"); add("its"); add("look"); add("then");
    add("who"); add("some"); add("good"); add("year"); add("into");
    add("they"); add("be"); add("end"); add("why");
    add("when");
    add("what");
    add("so");
    add("about");
    add("make");
    add("when");
    add("time");
    add("him");
    add("just");
    add("know");
    add("take");
    add("home");
    add("now");
    add("yes");
    add("today");
    add("no");

}

// function to generate random numbers from our trie
// using a custom user defined function as the rand() function is too slow for the computational algorithm
int x=42373, y=45672, z=78910;
int random(){
    int rnd;
    // using bitwise operation in order to get random numbers quickly
    x = x ^ (x << 10);
    x = x ^ (x >> 6);
    x = x ^ (x << 1);
   rnd = x ^ y ^ z;

  return rnd;
}

// our function to return a random variable from our trie
string get_rand(){
    trie* temp = new trie;
    temp = root;
    int rnd;
    char* word = new char[50];
    int i = 0;
    // making the char array empty
    for(int j = 0; j < 50; j++){
        word[i] = '\0';
    }

    // assigning a random word into our char array
    while(true){
        // getting a random number
        rnd = random() % 26;
        // if the number is negative make it positive
        if(rnd < 0){
            rnd = rnd * (-1);
        }
        // if the node at our random number doesnt exist run loop again for another random number
        if(temp->child[rnd] == NULL){
            continue;
        }
        else if(temp->child[rnd] != NULL){
            // the random generated alphabet should be between a-z
            if (static_cast<int>(getData(temp->child[rnd])) > 122 && static_cast<int>(getData(temp->child[rnd])) < 97){
                continue;
            }
            // assign the random character into our char array
            word[i] = getData(temp->child[rnd]);
            i++;
            // if a word is assigned then break the loop
            if(temp->child[rnd]->end > 0){
                break;
            }
        }
        // move onto the next child
        temp = temp->child[rnd];
        // if a word is assigned break the loop
        if(getEnd(temp) > 0){
            break;
        }
    }
    // return the random word
    return word;
}

int main(){
    // assigning a value to our root node
    root = newNode('/');
    // adding words into our trie
    add_words();

    // variables to be used for taking and saving the user input
    char words;
    char* input = new char[100];
    for(int j = 0; j < 100; j++){
        input[j] = '\0';
    }
    int i = 0;
    string s;
    string rand[4];
    bool unique = true;
    string test;

    for(int j = 0; j < 20; j++){
        test = get_rand();
    }

    int xlegnth;
    string select;

    cout << "Insert Your String!!" << endl;
    while(true){
        // getting the user input from the console at run time
        words = getch();

        // if the user enters the key '1' then insert the 1st suggestion into our list of characters entered
        if(static_cast<int>(words) == 49){
            input[i] = ' ';
            i++;
            select = rand[0];
            for(int k = 0; k < rand[0].length(); k++){
                input[i] = select[k];
                i++;
            }
        }
        // if the user enters the key '2' then insert the 1st suggestion into our list of characters entered
        else if(static_cast<int>(words) == 50){
            input[i] = ' ';
            i++;
            select = rand[1];
            for(int k = 0; k < rand[1].length(); k++){
                input[i] = select[k];
                i++;
            }
        }
        // if the user enters the key '3' then insert the 1st suggestion into our list of characters entered
        else if(static_cast<int>(words) == 51){
            input[i] = ' ';
            i++;
            select = rand[2];
            for(int k = 0; k < rand[2].length(); k++){
                input[i] = select[k];
                i++;
            }
        }
        // if the user enters the key '4' then insert the 1st suggestion into our list of characters entered
        else if(static_cast<int>(words) == 52){
            input[i] = ' ';
            i++;
            select = rand[3];
            for(int k = 0; k < rand[3].length(); k++){
                input[i] = select[k];
                i++;
            }
        }

        // if the user presses esc key then exit the program
        if(static_cast<int>(words) == 27){
            break;
        }

        // saving the user entered words into our char array
        if((static_cast<int>(words) <= 122 && static_cast<int>(words) >= 97) || static_cast<int>(words) == 32){
            input[i] = words;
            i++;
        }

        // if the user presses space bar then do not generate next word suggestions
        if(static_cast<int>(words) == 32){
            continue;
        }

        // get four random words from our trie that will be used for suggestions
        for(int j = 0; j < 4; j++){
            rand[j] = get_rand();
        }

        // clear the screen after each user input
        std::system("CLS");

        // telling the user how to select the suggested words
        std::cout << "Press 1,2,3 or 4 to insert the respective word into your line!! Press ESC key to Exit!!" << endl << endl;

        // display the string entered by the user onto the console
        for(int j = 0; j < 100; j++){
            if((input[j] == '\0') || (input[j] < 97 && input[j] > 122)){
                break;
            }
            std::cout << input[j];
        }

        // move the ouput window down as suggested in the document
        std::cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;

        // display the next suggestions to the user
        for(int j = 0; j < 4; j++){
            std::cout << j+1 << "." << rand[j] << "\t\t";
        }
        std::cout << endl;

    }

    cout << endl << endl;
    std::system("PAUSE");

    return 0;
}