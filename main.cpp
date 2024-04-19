#include "csm.h"
#include <iostream>
using namespace std;
int main(){
  CSM manager;
  if(manager.loadF("snippets.txt")){
    cout<<"Snippet loaded from file :)"<<endl;
  }else{
    cout<<"No saved snippets found :( Starting with an empty manager"<<endl;
  }
  while(true){
    cout<<"Choose and option: "<<endl;
    cout<<" 1. Add snippet"<<endl;
    cout<<" 2. Get snippet"<<endl;
    cout<<" 3. Delete snippet"<<endl;
    cout<<" 4. Edit snippet"<<endl;
    cout<<" 5. Search snippets"<<endl;
    cout<<" 6. Get code template"<<endl;
    cout<<" 7. Exit app"<<endl;
    int choice;
    cin>>choice;
    if(choice==1){
      string tag,code;
      cout<<"Enter tag: ";
      cin>>tag;
      cin.ignore();
      cout<<"Enter the code snippet\n";
      string line;
      code="";
      while(getline(cin,line) && line!="%%"){
        code+=line+"\n";
      }
      manager.addS(tag,code);
      cout<<"Snippet added :)"<<endl;
    }else if(choice==2){
      string tag;
      cout<<"Enter the tag linked to your required snippet: "<<endl;
      cin>>tag;
      manager.getS(tag);
    } else if(choice==7){
      manager.saveF("snippets.txt");
      cout<<"Snippets saved to file. Exiting app;";
      exit(0);
    }else if(choice==3){
        string tag;
        cout<<"Enter the tag linked to the snippet you want to delete: "<<endl;
        cin>>tag;
        manager.deleteS(tag);
      }else if(choice==4){
        string tag;
        cout<<"Enter the tag linked to the snippet you want to edit: "<<endl;
        cin>>tag;
        cin.ignore();
        cout<<"Enter the new code snippet\n";
        string line;
        string newCode = "";
        while(getline(cin,line) && line!="%%"){
          newCode += line+"\n";
        }
        manager.editS(tag, newCode);
      } else if(choice==5){
        string keyword;
        cout << "Enter the keyword to search for in tags or code: ";
        cin >> keyword;
        manager.search(keyword);
      }else if(choice==6){
      string tag;
      cout<<"Enter the tag for the code template you want to retrieve: options are: loop, condiotional, function";
      cin>>tag;
      string templateCode = manager.getTemplate(tag);
      cout << "Code Template for tag " << tag << ":" << endl;
      cout << templateCode << endl;
    }
    else{
      cout<<"Skill issue. Please enter a valid choice";
    }
  }
  return 0;
}
// #include "csm.h"
// #include <iostream>
// #include <highlight/highlight.h> 
// #include <string>
// using namespace std;

// int main() {
//     CSM manager;
//     if (manager.loadF("snippets.text")) {
//         cout << "Snippet loaded from file :)" << endl;
//     } else {
//         cout << "No saved snippets found :( Starting with an empty manager" << endl;
//     }

//     while (true) {
//         cout << "Choose an option: " << endl;
//         cout << " 1. Add snippet" << endl;
//         cout << " 2. Get snippet" << endl;
//         cout << " 3. Exit app" << endl;
//         int choice;
//         cin >> choice;
//         if (choice == 1) {
//             string tag, code;
//             cout << "Enter tag: ";
//             cin >> tag;
//             cin.ignore();
//             cout << "Enter the code snippet\n";
//             string line;
//             code = "";
//             while (getline(cin, line) && line != "%%") {
//                 code += line + "\n";
//             }
//             auto lang = hljs::highlight_auto(code);
//             manager.addS(tag, code, lang.second); 
//             cout << "Snippet added :)" << endl;
//         } else if (choice == 2) {
//             string tag;
//             cout << "Enter the tag linked to your required snippet: " << endl;
//             cin >> tag;
//             manager.getS(tag);
//         } else if (choice == 3) {
//             manager.saveF("snippets.txt");
//             cout << "Snippets saved to file. Exiting app;";
//             break;
//         } else {
//             cout << "Skill issue. Please enter a valid choice";
//         }
//     }

//     return 0;
// }
