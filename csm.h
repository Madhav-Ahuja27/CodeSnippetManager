#ifndef CSM_H
#define CSM_H
#include <string>
#include <map>
using namespace std;
class CSM{
  private:
    map<string,string> snippets;
  public:
  void addS(const string&tag, const string& code);
  void getS(const string& tag);
  void deleteS(const string& tag);
  bool saveF(const string& filename);
  bool loadF(const string& filename);
  void editS(const string& tag, const string& newCode);\
  void search(const string& keyword);
  string getTemplate(const string& tag);
};
#endif
