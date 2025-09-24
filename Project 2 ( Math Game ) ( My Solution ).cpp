#include <iostream>
using namespace std;

enum EnLevelChoice { Easy = 1 , Med = 2 , Hard = 3 , Mixlevel = 4 };

enum EnTypeChoice { Add = 1 , Sub = 2 , Mul = 3 , Div = 4 , Mixtype = 5 };

struct InformationInEvryRond
{
    int NumberAnswer = 0  ;
    EnLevelChoice Player1ChoiceLevel;
    EnTypeChoice  Player1ChoiceTypeOpertion;
  
    
};

struct ResultAnswer
{
    int NumberAnswer = 0 ;
    int NumberRight  = 0 ;
    int NumberWrong  = 0 ;
    string        Nomlevel     = "";
    string        Nomtype      = "";
};

int Random(int from , int to )
{
    return (rand() % (to - from + 1 ) + from );
}    

int ChoiceNumberLevel(int NumberLevel)
{
    return (EnLevelChoice::Easy == NumberLevel) ? Random(1,10) 
    : (EnLevelChoice::Med  == NumberLevel) ? Random(10,30) 
    : (EnLevelChoice::Hard == NumberLevel) ? Random(30,100)
    : Random(1,100);
    
}         

int HowManyAnswer()
{
    int Number;
    do
    {
        cout<<"\nHow Many Questions so you want to answer ? ";
        cin>>Number;
    } while (Number < 1 );
    return Number;
}

EnLevelChoice ChoicePlayerLevel()
{
    int number;
    do
    {
        cout<<"Enter Question Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";
        cin>>number;
    } while (number < 1 ||number > 4);
    return (EnLevelChoice)number;
}

EnTypeChoice ChoicePlayerType()
{
    int number;
    do
    {
        cout<<"Enter Question Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ";
        cin>>number;
    } while (number < 1 ||number > 5);
    return (EnTypeChoice)number;
}

string GetNomLevelChoice(int NumberLevel)
{
    string arrLevel[4] = { "Easy" , "Med" , "Hard" , "Mixlevel" };
    return arrLevel[NumberLevel - 1];
}

string GetNomTypeChoice(int NumberType)
{
    string arrType[5] =  { "Add" , "Sub" , "Mul" , "Div" , "Mixtype" };
    return arrType[NumberType - 1];
}

void MaxType(int &Number1 ,int &Number2,int &NumberRight,int &NumberWrong,InformationInEvryRond  &info);

void PartieOperation(int &Number1 ,int &Number2,int &NumberRight,int &NumberWrong,InformationInEvryRond  &info)
{
    int answer = 0 ;
    if(info.Player1ChoiceTypeOpertion == EnTypeChoice::Sub)
    {
    cout<<"\n"<<Number1<<endl<<Number2<<" -\n\n ________________\n";  
                cin>>answer;
                if (answer == (Number1 - Number2))
                {
                    cout << "\033[42;97m";
                    cout<<"Right Answer : -)";
                    ++NumberRight;
                   cout << "\033[0m";
                }    
                else 
                {
                    cout << "\033[41;97m";

                    cout<<"Wrong Asnwer : -(\n The Right answer is : "<<Number1-Number2<<endl;
                    ++NumberWrong;
                     cout << "\033[0m";

                } 
    }
    else if(info.Player1ChoiceTypeOpertion == EnTypeChoice::Add)
    {
    cout<<"\n"<<Number1<<endl<<Number2<<" +\n\n ________________\n";  
                cin>>answer;
                if (answer == (Number1 + Number2))
                {
                    cout << "\033[42;97m";

                    cout<<"Right Answer : -)";
                    ++NumberRight;
                    cout << "\033[0m";

                }    
                else 
                {
                    cout << "\033[41;97m";

                    cout<<"Wrong Asnwer : -(\n The Right answer is : "<<Number1+Number2<<endl;
                    ++NumberWrong;
                    cout << "\033[0m";

                } 
    }
    else if(info.Player1ChoiceTypeOpertion == EnTypeChoice::Mul)
    {
         cout<<"\n"<<Number1<<endl<<Number2<<" *\n\n ________________\n";  
                cin>>answer;
                if (answer == (Number1 * Number2))
                {
                    cout << "\033[42;97m";

                    cout<<"Right Answer : -)";
                    ++NumberRight;
                    cout << "\033[0m";

                }    
                else 
                {
                    cout << "\033[41;97m";

                    cout<<"Wrong Asnwer : -(\n The Right answer is : "<<Number1*Number2<<endl;
                    ++NumberWrong;
                    cout << "\033[0m";

                } 
    }
    else if(info.Player1ChoiceTypeOpertion == EnTypeChoice::Div)
    {
         cout<<"\n"<<Number1<<endl<<Number2<<" /\n\n ________________\n";  
                cin>>answer;
                if (answer == (Number1 / Number2))
                {
                    cout << "\033[42;97m";

                    cout<<"Right Answer : -)";
                    ++NumberRight;
                    cout << "\033[0m";

                }     
                else 
                {
                    cout << "\033[41;97m";

                    cout<<"Wrong Asnwer : -(\n The Right answer is : "<<Number1/Number2<<endl;
                    ++NumberWrong;
                    cout << "\033[0m";

                } 
    }
  
}

void MaxType(int &Number1 ,int &Number2,int &NumberRight,int &NumberWrong,InformationInEvryRond &info)
{
    int NumberMaxType = Random(1,5);
    if(NumberMaxType == EnTypeChoice::Add)
    {
        info.Player1ChoiceTypeOpertion = EnTypeChoice::Add;
        PartieOperation(Number1,Number2,NumberRight,NumberWrong,info);
    }
    else if(NumberMaxType == EnTypeChoice::Sub)
    {
        info.Player1ChoiceTypeOpertion = EnTypeChoice::Sub;
        PartieOperation(Number1,Number2,NumberRight,NumberWrong,info);

    }
    else if(NumberMaxType == EnTypeChoice::Mul)
    {
        info.Player1ChoiceTypeOpertion = EnTypeChoice::Mul;
        PartieOperation(Number1,Number2,NumberRight,NumberWrong,info);

    }
    else 
    {
        info.Player1ChoiceTypeOpertion = EnTypeChoice::Div;
        PartieOperation(Number1,Number2,NumberRight,NumberWrong,info);

    }
   
}

ResultAnswer CalculeOperation(int &NumberPlay) 
{
    InformationInEvryRond info;
    int Number1 = 0 ,Number2 = 0 ,NumberRight = 0 , NumberWrong = 0 ;
    info.NumberAnswer              = NumberPlay;
    info.Player1ChoiceLevel        = ChoicePlayerLevel();
    info.Player1ChoiceTypeOpertion = ChoicePlayerType();
    for(int i = 1 ; i <= NumberPlay ; i++)
    {
      cout<<"\n\nQuestion ["<<i<<"/"<<NumberPlay<<"]\n\n";
    switch (info.Player1ChoiceLevel)
    {
    case EnLevelChoice::Easy:
         Number1 = ChoiceNumberLevel(EnLevelChoice::Easy);
         Number2 = ChoiceNumberLevel(EnLevelChoice::Easy);
         if(info.Player1ChoiceTypeOpertion == EnTypeChoice::Add 
            || info.Player1ChoiceTypeOpertion == EnTypeChoice::Sub
            || info.Player1ChoiceTypeOpertion == EnTypeChoice::Mul
            || info.Player1ChoiceTypeOpertion == EnTypeChoice::Div
            || info.Player1ChoiceTypeOpertion == EnTypeChoice::Mixtype

         )
         {
            PartieOperation(Number1,Number2,NumberRight,NumberWrong,info);
            break;
         }
      
    case EnLevelChoice::Med:
         Number1 = ChoiceNumberLevel(EnLevelChoice::Med);
         Number2 = ChoiceNumberLevel(EnLevelChoice::Med);
         if(info.Player1ChoiceTypeOpertion == EnTypeChoice::Add
        || info.Player1ChoiceTypeOpertion == EnTypeChoice::Sub
        || info.Player1ChoiceTypeOpertion == EnTypeChoice::Mul
        || info.Player1ChoiceTypeOpertion == EnTypeChoice::Div
        || info.Player1ChoiceTypeOpertion == EnTypeChoice::Mixtype

        ) 
         {
            PartieOperation(Number1,Number2,NumberRight,NumberWrong,info);
            break;
         }
       
    case EnLevelChoice::Hard:
         Number1 = ChoiceNumberLevel(EnLevelChoice::Hard);
         Number2 = ChoiceNumberLevel(EnLevelChoice::Hard);
         if(info.Player1ChoiceTypeOpertion == EnTypeChoice::Add
        || info.Player1ChoiceTypeOpertion == EnTypeChoice::Sub
        || info.Player1ChoiceTypeOpertion == EnTypeChoice::Mul
        || info.Player1ChoiceTypeOpertion == EnTypeChoice::Div
        || info.Player1ChoiceTypeOpertion == EnTypeChoice::Mixtype

        )
         {
            PartieOperation(Number1,Number2,NumberRight,NumberWrong,info);
            break;
         }
    case EnLevelChoice::Mixlevel:
         Number1 = ChoiceNumberLevel(EnLevelChoice::Mixlevel);
         Number2 = ChoiceNumberLevel(EnLevelChoice::Mixlevel);
         if(info.Player1ChoiceTypeOpertion == EnTypeChoice::Add
        || info.Player1ChoiceTypeOpertion == EnTypeChoice::Sub
        || info.Player1ChoiceTypeOpertion == EnTypeChoice::Mul
        || info.Player1ChoiceTypeOpertion == EnTypeChoice::Div
        || info.Player1ChoiceTypeOpertion == EnTypeChoice::Mixtype

        )
         {
            MaxType(Number1,Number2,NumberRight,NumberWrong,info);
            info.Player1ChoiceTypeOpertion = EnTypeChoice::Mixtype;
            break;
         }
    }
}
    return {NumberPlay,NumberRight,NumberWrong,GetNomLevelChoice(info.Player1ChoiceLevel),GetNomTypeChoice(info.Player1ChoiceTypeOpertion)};

  }



void TracerTableResult(ResultAnswer info)
{
    string result;
   if(info.NumberRight > info.NumberWrong) 
   {
     result = "Final Results is PASS : -)";
   }
   else if(info.NumberRight < info.NumberWrong) 
   {
     result = "Final Results is FAIL : -(";

   }
   else
   {
    result = "Final Results is DRAW : (-_-) ";
   }

    cout<<"\n\n___________________________________\n";
    cout<<result<<endl;
    cout<<"___________________________________\n\n";
    cout<<"Number of Questions     : "<<info.NumberAnswer<<endl;
    cout<<"Questions Level         : "<<info.Nomlevel<<endl;
    cout<<"Optype                  : "<<info.Nomtype<<endl;
    cout<<"Number of Right Answers : "<<info.NumberRight<<endl;
    cout<<"Number of Wrong Answers : "<<info.NumberWrong<<endl;
    cout<<"___________________________________\n\n";


}
void AddColorTracerTableResult(ResultAnswer info)
{
      if(info.NumberRight > info.NumberWrong) 
   {
    cout << "\n\n\033[42;97m";
    TracerTableResult(info);
    cout << "\033[0m";
   }
   else if(info.NumberRight < info.NumberWrong) 
   {
    cout << "\n\n\033[41;97m";
    TracerTableResult(info);
    cout << "\033[0m";
   }
   else
   {
    cout << "\n\n\033[43;97m";
    TracerTableResult(info);
    cout << "\033[0m";
   }

}


void ResultFinal()
{
    string Resutl;
    do
    {
        system("clear");   // i Have Linux 
    int Number = HowManyAnswer();

    ResultAnswer infoR = CalculeOperation(Number);
    
    AddColorTracerTableResult(infoR);
    cout<<"\nDo you want to play again ? Y/N ? ";
    cin>>Resutl;
    } while (Resutl == "Y" || Resutl == "y");
    
    cout<< "🥱🥱 Goodbye 🥱🥱";
}
int main()
{
    srand(time(NULL));
    ResultFinal();
}