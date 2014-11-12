#include <iostream>
#include<windows.h>
#include <stdio.h>
//#include <io.h>

using namespace std;

class AudioObj
{
public:
    AudioObj(const char* a_path);
    ~AudioObj();


private:
    string name = "NULL";
    string artist = "NULL";
    string album = "NULL";
    string genre = "NULL";
    string comment = "NULL";
    string filename = "NULL";
    string path = "NULL";
    string filetype = "mp3";

    int year = 0;
};

AudioObj::AudioObj(const char* a_path)
    :path(a_path)
{
    //
}

AudioObj::~AudioObj()
{

}

int main()
{
    WIN32_FIND_DATA FindFileData;
    HANDLE hf;
    hf=FindFirstFile("I:\\SEREGA\\MUSIK\\*", &FindFileData);

    //AudioObj track1("I:\\SEREGA\\MUSIK\\2010.mp3");

    //int return_code;
    //return_code = rename("I:\\SEREGA\\MUSIK\\2010.mp3", "I:\\SEREGA\\MUSIK\\its_work.mp3");



//------------------------------------------------------------------------------------
//---FILE_LIST------------------------------------------------------------------------
//------------------------------------------------------------------------------------
    if(hf!=INVALID_HANDLE_VALUE){
        do
        {
            const char *ptr_3_v_g = FindFileData.cFileName+(strlen(FindFileData.cFileName)-1); //3 v g ^ listing
            const char *ptr_p_a_g = FindFileData.cFileName+(strlen(FindFileData.cFileName)-2); //p a g | from down
            const char *ptr_m_w_o = FindFileData.cFileName+(strlen(FindFileData.cFileName)-3); //m w o | to up (filetypes)
            if(strchr(ptr_3_v_g,'3'))
            {
                if(strchr(ptr_p_a_g,'p'))
                {
                    if(strchr(ptr_m_w_o,'m'))
                    {
                        cout<<FindFileData.cFileName<<"\n";
                    }
                }
            }else
            if(strchr(ptr_3_v_g,'v'))
            {
                if(strchr(ptr_p_a_g,'a'))
                {
                    if(strchr(ptr_m_w_o,'w'))
                    {
                        cout<<FindFileData.cFileName<<"\n";
                    }
                }
            }else
            if(strchr(ptr_3_v_g,'g'))
            {
                if(strchr(ptr_p_a_g,'g'))
                {
                    if(strchr(ptr_m_w_o,'o'))
                    {
                        cout<<FindFileData.cFileName<<"\n";
                    }
                }
            }
        }
        while (FindNextFile(hf,&FindFileData)!=0);
        FindClose(hf);
    }
//------------------------------------------------------------------------------------
//---FILE_LIST_END--------------------------------------------------------------------
//------------------------------------------------------------------------------------





    return 0;
}
