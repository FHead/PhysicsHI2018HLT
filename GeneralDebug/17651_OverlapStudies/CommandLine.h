#include <map>
#include <vector>
#include <iostream>

class CommandLine
{
private:
   std::string Self;
   std::map<std::string, std::string> Arguments;
   std::vector<std::string> ExtraArguments;
public:
   CommandLine(int argc, char *argv[]);
   ~CommandLine();
   void Initialize(int argc, char *argv[]);
   std::string operator [](int Index);
   std::string operator [](std::string Key);
   std::string Get(int Index);
   std::string Get(std::string Key);
   std::string Get(int Index, std::string Default);
   std::string Get(std::string Key, std::string Default);
   int GetInt(int Index);
   int GetInt(std::string Key);
   int GetInt(int Index, int Default);
   int GetInt(std::string Key, int Default);
   double GetDouble(int Index);
   double GetDouble(std::string Key);
   double GetDouble(int Index, double Default);
   double GetDouble(std::string Key, double Default);
   bool GetBool(int Index);
   bool GetBool(std::string Key);
   bool GetBool(int Index, bool Default);
   bool GetBool(std::string Key, bool Default);
   bool StringToBool(string String);
   std::string GetSelf();
};

CommandLine::CommandLine(int argc, char *argv[])
{
   Initialize(argc, argv);
}

CommandLine::~CommandLine()
{
}

void CommandLine::Initialize(int argc, char *argv[])
{
   Self = "";
   Arguments.clear();
   ExtraArguments.clear();

   if(argc < 1)
      return;

   Self = argv[0];

   for(int i = 1; i < argc; i++)
   {
      if(argv[i][0] != '-')
         ExtraArguments.push_back(argv[i]);
      else
      {
         bool ForceNext = false;
         if(argv[i][1] == '-')   // note since [0] is '-', there must be a [1]: '\0' for short string
            ForceNext = true;

         std::string Key = argv[i];
         while(Key.size() > 0 && Key[0] == '-')
            Key.erase(Key.begin());

         if(ForceNext == false && (i + 1 >= argc || argv[i+1][0] == '-'))
            Arguments.insert(std::pair<std::string, std::string>(Key, "1"));
         else
         {
            Arguments.insert(std::pair<std::string, std::string>(Key, argv[i+1]));
            i = i + 1;
         }
      }
   }
}

std::string CommandLine::operator [](int Index)
{
   return Get(Index);
}

std::string CommandLine::operator [](std::string Key)
{
   return Get(Key);
}

std::string CommandLine::Get(int Index)
{
   if(Index < 0 || Index >= ExtraArguments.size())
   {
      std::cerr << "Exception: argument index out of range" << std::endl;
      throw;
   }
   
   return ExtraArguments[Index];
}
   
std::string CommandLine::Get(std::string Key)
{
   if(Arguments.find(Key) == Arguments.end())
   {
      std::cerr << "Exception: Key \"" << Key << "\" not found in arguments" << std::endl;
      throw;
   }

   return Arguments[Key];
}

std::string CommandLine::Get(int Index, std::string Default)
{
   if(Index < 0 || Index >= ExtraArguments.size())
      return Default;
   
   return ExtraArguments[Index];
}
   
std::string CommandLine::Get(std::string Key, std::string Default)
{
   if(Arguments.find(Key) == Arguments.end())
      return Default;

   return Arguments[Key];
}

int CommandLine::GetInt(int Index)
{
   return atoi(Get(Index).c_str());
}

int CommandLine::GetInt(std::string Key)
{
   return atoi(Get(Key).c_str());
}

int CommandLine::GetInt(int Index, int Default)
{
   std::string Result = Get(Index, "");
   if(Result == "")
      return Default;
   return atoi(Result.c_str());
}

int CommandLine::GetInt(std::string Key, int Default)
{
   std::string Result = Get(Key, "");
   if(Result == "")
      return Default;
   return atoi(Result.c_str());
}

double CommandLine::GetDouble(int Index)
{
   return atof(Get(Index).c_str());
}

double CommandLine::GetDouble(std::string Key)
{
   return atof(Get(Key).c_str());
}

double CommandLine::GetDouble(int Index, double Default)
{
   std::string Result = Get(Index, "");
   if(Result == "")
      return Default;
   return atof(Result.c_str());
}

double CommandLine::GetDouble(std::string Key, double Default)
{
   std::string Result = Get(Key, "");
   if(Result == "")
      return Default;
   return atof(Result.c_str());
}

bool CommandLine::GetBool(int Index)
{
   string String = Get(Index);
   return StringToBool(String);
}

bool CommandLine::GetBool(std::string Key)
{
   string String = Get(Key);
   return StringToBool(String);
}

bool CommandLine::GetBool(int Index, bool Default)
{
   std::string String = Get(Index, (Default ? "true" : "false"));
   return StringToBool(String);
}

bool CommandLine::GetBool(std::string Key, bool Default)
{
   std::string String = Get(Key, (Default ? "true" : "false"));
   return StringToBool(String);
}

bool CommandLine::StringToBool(string String)
{
   if(String == "1")   return true;
   if(String == "0")   return false;

   if(String == "true")    return true;
   if(String == "false")   return false;

   if(String == "True")    return true;
   if(String == "False")   return false;

   if(String == "TRUE")    return true;
   if(String == "FALSE")   return false;

   std::cerr << "Exception: boolean value \"" << String << "\" not recognized." << std::endl;
   throw;
   
   return false;
}

std::string CommandLine::GetSelf()
{
   return Self;
}


