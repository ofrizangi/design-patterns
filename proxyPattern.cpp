// proxy pattern - caching proxy

#include <iostream>
#include <vector>

using namespace std;

//youtube interface
class Youtube{
public:
    virtual string downloadVideo(string id) = 0;
};

class realYotubeDownloader: public Youtube{
public:
    virtual string downloadVideo(string id){
        return id;
    }
};

class YoutubeProxy: public Youtube{
    realYotubeDownloader * r;
    vector <string > * cacheList;
public:
    YoutubeProxy(){
        this->r = new realYotubeDownloader();
        this->cacheList = new vector<string>();
    }

    virtual string downloadVideo(string id){
        vector<string>:: iterator it;
        for(it = cacheList->begin(); it!= cacheList->end(); it++){
            if(*it == id){
                cout << "cached the video: " << id << '\n';
                return "done";
            }
        }
        string s= r->downloadVideo(id);
        cacheList->push_back(s);
        cout << "downloaded the video: " + s + '\n';
        return "done";
    }
    ~YoutubeProxy(){
        delete r;
    }
};


int main() {
    Youtube * y = new YoutubeProxy();
    y->downloadVideo("hello");
    y->downloadVideo("hello");
    y->downloadVideo("pass");
    return 0;
}
