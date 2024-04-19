#include "csm.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void CSM::addS(const string&tag, const string& code){
  snippets[tag]=code;
}
void CSM::getS(const string& tag){
  auto it = snippets.find(tag);
  if(it!=snippets.end()){
    cout<<"Snippet for tag: "<< tag<<": "<<endl;
    cout<<it->second<<endl;
  }else{
    cout<<"404 Snippet not found :("<<endl;
  }
}
void CSM::deleteS(const string& tag){
  auto it = snippets.find(tag);
  if(it!=snippets.end()){
    snippets.erase(it);
    cout<<"Snippet for tag "<< tag <<" deleted successfully"<<endl;
  }else{
    cout<<"404 Snippet not found :("<<endl;
  }
}

bool CSM::saveF(const string& filename){
  ofstream outFile(filename);
  if(!outFile){
    cout<<"Unable to open file for writing :(";
    return false;
  }
  for(const auto& entry: snippets){
    outFile <<"Tag: "<<entry.first<<endl;
    outFile <<"Code:\n "<<entry.second<<endl;
  }
  outFile.close();
  cout<<endl<<"Snippets saved to file: "<<filename<<" :)"<<endl;
  return true;
}
void CSM::editS(const string& tag, const string& newCode){
  auto it = snippets.find(tag);
  if(it!=snippets.end()){
    snippets[tag] = newCode;
    cout<<"Snippet for tag "<< tag <<" edited successfully"<<endl;
  }else{
    cout<<"404 Snippet not found :("<<endl;
  }
}

bool CSM::loadF(const string& filename){
  ifstream ifile(filename);
  if(!ifile){
    cout<<"Unable to open file for reading :("<<endl;
    return false;
  }
  snippets.clear();
  string line;
  string currTag;
  string currCode;

  while(getline(ifile,line)){
    if(line.find("Tag: ") == 0){
      currTag=line.substr(5);
    }else if(line.find("Code:") == 0){
      currCode="";
      while(getline(ifile,line) && line!=""){
        currCode+= line+"\n";
      }
      snippets[currTag]=currCode;
    }
  }
  ifile.close();
  cout<<"Snippet loaded from file: "<<filename<<endl;
  return true;
}
void CSM::search(const string& keyword){
  bool found = false;
  for(const auto& entry : snippets){
    if(entry.first.find(keyword) != string::npos || entry.second.find(keyword) != string::npos){
      cout << "Tag: " << entry.first << endl;
      cout << "Code:\n" << entry.second << endl;
      found = true;
    }
  }
  if(!found){
    cout << "No snippets found containing keyword: " << keyword << endl;
  }
}
string CSM::getTemplate(const string& tag){
  if (tag == "loop") {
    return "for (int i = 0; i < N; ++i) {\n\t// Your code here\n}";
  } else if (tag == "conditional") {
    return "if (condition) {\n\t// Your code here\n} else {\n\t// Your code here\n}";
  } else if (tag == "function") {
    return "void functionName() {\n\t// Your code here\n}";
  } else {
    return "No template found for tag: " + tag;
  }
}
