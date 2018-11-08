#ifndef BASICS_H
#define BASICS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class basics
{

private:

public:

    vector  <string> fileInput(string filename){

        vector <string> tmpVec;
        string line;
        ifstream myfile (filename);     // inputstream of file with defined name
        if (myfile.is_open()){

            while (!myfile.eof()){      // until end of file

                getline (myfile,line);
                tmpVec.push_back(line);

            }myfile.close();

        }else cerr << "Unable to open file"<<endl<<"did you run the project in shadowbuild?"<<endl;
        return tmpVec;
    }

    void fileOutput(vector <string> input,string filename){

        std::ofstream out(filename); // create file
        for (int i = 0; i<input.size();i++){
            out << input[i]<<endl;//write string in file
        }


        out.close(); // close editing
    }

    vector<string> stringDelimiter(const string& line, const string& delimiter, const string& substitute)
    {
        vector<string> tmpVec;
        size_t prev = 0, pos = 0;

        do
        {
            pos = line.find(delimiter, prev);
            if (pos == string::npos) pos = line.length();
            string tmpString = line.substr(prev, pos-prev);
            if (!tmpString.empty()) tmpVec.push_back(tmpString);
            prev = pos + delimiter.length();
        }
        while (pos < line.length() && prev < line.length());
        if(substitute != ""){
            string parsedstring= "";
            for(int i = 0; i<tmpVec.size();i++){
                parsedstring.append(tmpVec[i]);
                if(i!= tmpVec.size()-1) parsedstring.append(substitute);
            }
            tmpVec.clear();
            tmpVec.push_back(parsedstring);
        }return tmpVec;
    }

    void printVector(vector<string> givenString)
    {
        for (int i=0;  i <givenString.size();  i++)
        {
            cout<<givenString[i]<<endl;
        }
        cout<<endl;
    }









    // longest function
    vector<string> sortVector(vector<string> unsortedVector, int type_min_zero_max_nine){
        // TO DO implementing sortingalgorithms from http://www.sortieralgorithmen.de/
        while(true){

            switch (type_min_zero_max_nine) {
            case 7:{

            }

            case 8:{
                cout << "you've chosen Selectionsort"<<endl;

                int temp;
                for (int j = 0; j < unsortedVector.size() - 1; ++j) {
                    string min = unsortedVector[j];
                    temp = j;
                    for (int i = j+1; i < unsortedVector.size(); ++i) {
                        if (min > unsortedVector[i]) {
                            min = unsortedVector[i];
                            temp = i;
                        }
                    }
                    swap(unsortedVector[j], unsortedVector[temp]);
                }
                break;


            }
            case 9:{
                cout << "you've chosen Bubblesort"<<endl;

                string tmpString;
                bool swap = true;
                while(swap)
                {
                    swap = false;
                    for (int i = 0; i < unsortedVector.size()-1; i++)
                    {
                        if (unsortedVector[i]>unsortedVector[i+1] )
                        {
                            if(unsortedVector[i]>unsortedVector[i+1]){
                                tmpString = unsortedVector[i];
                                unsortedVector[i] = unsortedVector[i+1];
                                unsortedVector[i+1] = tmpString;
                                swap = true;
                            }
                            //else if (unsortedVector[i]<=unsortedVector[i+1]) {}
                        }
                    }
                }
                break;


            }
            default: cerr<<type_min_zero_max_nine<<" -Type nonexistent\t-choosing 9(Bubblesort)as default"<<endl;
                type_min_zero_max_nine = 9;
                continue;
            }
            return unsortedVector;
        }
    }







    /*    vector <string> parsevector(vector <string> muha){

        for (int i = 0; i<muha.size(); i++){
                    muha[i].at(0) = '(';
                    for (int j = 0; j<muha[i].size(); j++){
                        if (muha[i].at(j)== '|'){
                            muha[i].at(j) = ',';
                        }
                    }
                    muha[i] = muha[i]+')';

        }
        return muha;
     }

*/


};// headerende
#endif // BASICS_H
