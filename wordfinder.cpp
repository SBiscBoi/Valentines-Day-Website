#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    //array of required letters
    //char letters[9] = {'v', 'a', 'l', 'e', 'n', 't', 'i', 'n', 'e'}; //no null item needed, not going to be used as a "string"
    
    //get word file
    fstream wordFile("words_alpha.txt");
    //create output file
    ofstream goodWordFile("good_words.txt");
    //read line-by-line, output current line content to "word"
    string word;
    while(getline(wordFile, word)){     
        /* ~add acceptable words to goodWordFile~
            creteria to keep a word:
            - 1: The word is exactly 9 letters in length
            - 2: The word contains every single letter in the "letters" array
            - 3: The word contains the same amount of instances of each letter as it does in the "letters" array
        */
        bool goodWord = true; //innocent until proven guilty
        if(word.length() == 9){
            //length is correct, now search for letters, keeping track of the amount of occurances
                int count[7] = {0, 0, 0, 0, 0, 0, 0}; //each index corresponds to a unique letter in the word "valentine", index 8 is used to stop iteration early if an unexpected letter is read
                const int correctCount[7] = {2, 1, 1, 1, 2, 1, 1}; //what a valid word's "count" looks like
            for(int i = 0; i < 9; i++){
                switch(word[i]){
                    /*  *ordered in the (hopefully) most optimal way*
                        ~reference: https://www3.nd.edu/~busiforc/handouts/cryptography/letterfrequencies.html~
                        in terms of frequency in the english language, each unique letter in "valentine" is ranked as follows:
                        1: E (11.1607%)
                        2: A (8.4966%)
                        3: I (7.5448%)
                        4: T (6.9509%)
                        5: N (6.6544%)
                        6: L (5.4893%)
                        7: V (1.0074%)
                    */
                    case 'e': count[0]++; break;
                    case 'a': count[1]++; break;
                    case 'i': count[2]++; break;
                    case 't': count[3]++; break;
                    case 'n': count[4]++; break;
                    case 'l': count[5]++; break;
                    case 'v': count[6]++; break;
                }
            }

            //check if count matches the valid count
            for(int i = 0; i < 7; i++){
                if(count[i] != correctCount[i]){
                    //cout << "Count[i]: " << count[i] << " correctCount[i]: " << correctCount[i] << endl;
                    goodWord = false;
                    break;
                }
            }

        }
        else{
            goodWord = false;
        }

        if(goodWord){
            goodWordFile << word << endl;
            cout << "Good Word!" << endl;
        }
    }

    //terminate
    return 0;
}