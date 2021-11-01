#include <iostream>
#include <regex>
#include <string>
using namespace std;

void printMatches(string str,regex reg){
    smatch matches;
    while(regex_search(str,matches,reg)){      
        cout<<matches.str(1)<<"\n";//first match
        str=matches.suffix().str();
    }    
}

int main(){

    //Back reference: allows us re use an expression that preceed it

    //find double words
    string str1="The cat cat fell out the window";
    regex reg1("(\\b\\w+)\\s+\\1");//1 refers to the first match in the parenteses
    // printMatches(str1, reg1);

    //back reference substitution: remove bold tag
    string str2="<a href='#'><b>The link</b></a>";
    regex reg2("<b>(.*?)</b>");
    string result;
    //Insert the final result into the result string
    regex_replace(back_inserter(result), str2.begin(), str2.end(), reg2, "$1");
    // cout<<result<<endl;

    //put parenteses around area code
    string str3="412-555-1212";
    regex reg3("([\\d]{3})-([\\d]{3}-[\\d]{4})");//each () is an expression $
    string result1;
    regex_replace(back_inserter(result1), str3.begin(), str3.end(), reg3, "($1)$2");
    // cout<<result1;

    string str4 = "https://www.youtube.com "
            "http://www.google.com";
 
    // Grab the URL and then provide the following output
    // using a back reference substitution
    // <a href='https://www.youtube.com'>www.youtube.com</a>
    // <a href='https://www.google.com'>www.google.com</a>

    // regex reg4("[^http][://www.][\\w]{0,20}.[com]");
    regex reg4("(https?://([\\w.]+))");
    string result2;
    regex_replace(back_inserter(result2), str4.begin(), str4.end(), 
    reg4, "<a href='$1'>$2</a>\n");
    // cout<<result2;


    //Look Ahead: defines a patter to match but not return
    //return the word itself
    string str5=" one two three four";
    regex reg5("(\\w+(?=\\b))");
    // printMatches(str5, reg5);
    

    // OR Conditional
 
    string str6 = "1. Dog 2. Cat 3. Turtle"; 
    regex reg6 ("\\d\\.\\s(Dog|Cat)"); 
    // printMatches(str6,reg6);

    string str7="12345 12345-1234 1234 12346-333";
    regex reg7("([\\d]{5}-[\\d]{4}|\\d{5}\\s)");
    // printMatches(str7, reg7);

    string str8 = "14125551212 4125551212 "
            "(412)5551212 412 555 1212 412-555-1212 "
            "1-412-555-1212";

    regex reg8("((1?)(-| ?)(\\()?(\\d{3})(\\)|-| |\\))?(\\d{3})(-| )?(\\d{4}|\\d{4}))");
    printMatches(str8, reg8);



    return 0;
}