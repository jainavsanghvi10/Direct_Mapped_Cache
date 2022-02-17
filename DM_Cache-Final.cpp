#include<bits/stdc++.h>
using namespace std;
#define ll long long

void getval(vector<pair<ll,ll>>&DMcache,ll address,double* hits,double* misses,ll cachesize,ll blocksize){
    
//Calculation of the tag bits,index Bits,offset bits depending upon the blocksize and cache size.
    ll tag,index,offset;            
    offset=address%(blocksize);     
    index=(address%(cachesize*(1<<10)))/(blocksize);
    tag=address/(cachesize*(1<<10));    
    
//First check if the valid bit corresponding to the required line(index) is 0 or 1, to check if any data is present in that line index    
//valid bit=0 means, no data is present
//valid bit=1 means, data is prensent
 
//If the valid bit is 0 then,
//add the corrseponding tag bits of the address in the cache for future mapping purpose and, 
//set the valid bit as 1 and,
//increment the no. of misses by one

//If the valid bit is 1 then,
//Match the tag bits of the req address with the tag bits of the address of the data present in the cache
//If Match found, then increment the no. of hits by 1  
//If match not found, then increment the no. of misses by 1 and update the tag bits in the cache with tag bits 
    if(DMcache[index].first==0){    
        DMcache[index].second=tag;   
        DMcache[index].first=1;
        *misses+=1;
    }
    else{
        if(DMcache[index].second==tag){
            *hits+=1;
        }
        else{
            *misses+=1;
            DMcache[index].second=tag;
        }    
    }
}

void PrintResult(double hits,double misses){
//Prints the required results(hits,misses,hit ratio,miss ratio,hit/miss ratio) of the trace file in the terminal as output    
    double hratio=hits/(hits+misses);
    double mratio=1-hratio;
    cout<<"Hits: "<<hits<<"\tMisses: "<<misses<<"\tHit Ratio: ";
    printf("%0.15f",hratio);
    cout<<"   Miss Ratio: ";
    printf("%0.15f",mratio);
    printf("   Hit/Miss Ratio: %0.15f\n",hits/misses);
}

int main(){
	ll cachesize,blocksize,cacheline;
//Input from user regarding the specification of the direct map cache for implementation purpose.    
    cout<<"Enter cache size in KB: ";   
    cin>>cachesize;     

    cout<<"Enter block size in Bytes: ";
    cin>>blocksize;

    cacheline = (cachesize/blocksize)*(1<<10);
//Prints the total no. of lines in the cache
    cout<<"Number of lines/blocks in cache: "<<cacheline<<endl;
    
//----------------Trace File 1------------------------------------------------------------------------------------
    string str;
    //Implementing the blocks in cache memory using vector of pairs representing,  
    //1)valid bit and 2) the tag bits of the address(location) -corresponding to the data present         
    vector<pair<ll,ll>>DMcache(cacheline,make_pair(0,0));  //initializes the cache memory to 0
    double hits=0,misses=0;
    ifstream file;                      //ifstream-Stream class to read from files. creating a file object representing the input file stream and is used to read information from files
    file.open("./TraceFiles/gcc.trace");             //opening the file for reading purpose
    while(getline(file,str)){           //reads all the lines in the file untill no line is encountered and stores it in string str,while doing so the previously stored value in the string object str will be replaced by the input string if any.      
        string address=str.substr(4,8); //extracts the address from the string and stores it in string address 
        ll adrs;
        adrs=stol(address,0,16);        //converts the string(in hexadecimal format) to long long int in decimal format
        getval(DMcache,adrs,&hits,&misses,cachesize,blocksize); //finds if its a hit or miss in cache memory and updates the variables accordingly
    }
    cout<<"1) gcc.trace:-     ";        //prints the file name
    PrintResult(hits,misses);           //prints the required result 
    file.close();                       //Closes the last opened file
    DMcache.assign(DMcache.size(),make_pair(0,0));  //resets the cache memory to 0.

//----------------Trace File 2------------------------------------------------------------------------------------
    hits=0,misses=0;
    file.open("./TraceFiles/gzip.trace");
    while(getline(file,str)){        
        string address=str.substr(4,8);
        ll adrs;
        adrs=stol(address,0,16);
        getval(DMcache,adrs,&hits,&misses,cachesize,blocksize);
    }
    cout<<"2) gzip.trace:-    ";
    PrintResult(hits,misses);
    file.close();
    DMcache.assign(DMcache.size(),make_pair(0,0));

//----------------Trace File 3------------------------------------------------------------------------------------
    hits=0,misses=0;
    file.open("./TraceFiles/mcf.trace");
    while(getline(file,str)){        
        string address=str.substr(4,8);
        ll adrs;
        adrs=stol(address,0,16);
        getval(DMcache,adrs,&hits,&misses,cachesize,blocksize);
    }
    cout<<"3) mcf.trace:-     ";
    PrintResult(hits,misses);
    file.close();
    DMcache.assign(DMcache.size(),make_pair(0,0));

//----------------Trace File 4------------------------------------------------------------------------------------
    hits=0,misses=0;
    file.open("./TraceFiles/swim.trace");
    while(getline(file,str)){        
        string address=str.substr(4,8);
        ll adrs;
        adrs=stol(address,0,16);
        getval(DMcache,adrs,&hits,&misses,cachesize,blocksize);
    }
    cout<<"4) swim.trace:-    ";
    PrintResult(hits,misses);
    file.close();
    DMcache.assign(DMcache.size(),make_pair(0,0));

//----------------Trace File 5------------------------------------------------------------------------------------
    hits=0,misses=0;
    file.open("./TraceFiles/twolf.trace");
    while(getline(file,str)){        
        string address=str.substr(4,8);
        ll adrs;
        adrs=stol(address,0,16);
        getval(DMcache,adrs,&hits,&misses,cachesize,blocksize);
    }
    cout<<"5) twolf.trace:-   ";
    PrintResult(hits,misses);
    file.close();
    DMcache.assign(DMcache.size(),make_pair(0,0));


return 0;  
}
