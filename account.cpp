#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
bool check(string,string);
bool time(string,string);
class Node
{
public:
    string item;
    int value;
    string time;
    Node *next;
    Node() {
        value=0;
        next=NULL;
    }
    Node(string _item, int _value, string _time) {
        item=_item;
        value=_value;
        time=_time;
        next=NULL;
    }
};
enum Mode{DEFAULT,ITEM,VALUE,TIME};
class Account
{
public:
    Node *first;
    Mode mode;
    Account(Mode _mode=DEFAULT) {
        first=NULL;
        mode=_mode;
    }
    ~Account() {
        while(first!=NULL)
            erase();
    }
    void insert(string _item, int _value, string _time) {
        if (first == NULL){
            first = new Node(_item, _value, _time);
        }
        else
        {
            if(mode==0){
               Node *p=new Node(_item, _value, _time);
               p->next=first;
               first=p;
            }
            else if(mode==1){
                Node *p=new Node(_item, _value, _time);
                Node *q= first;
                Node *r= NULL;
                int a=0;
                while (check(p->item,q->item)){
                        r=q;
                        q=q->next;
                        a++;
                        if(q==NULL)
                            break;
                }
                if(a!=0){
                    p->next=q;
                    r->next=p;
                }
                else{
                    p->next=first;
                    first=p;
                }
                
            }
            else if(mode==2){
                Node *p=new Node(_item, _value, _time);
                Node *q=first;
                Node *r=NULL;
                int a=0;
                while (p->value>=q->value){
                    r=q;
                    q=q->next;
                    a++;
                    if(q==NULL)
                        break;
                }
                if(a!=0){
                    p->next=q;
                    r->next=p;
                }
                else{
                    p->next=first;
                    first=p;
                }
            }
            else {
                Node *p=new Node(_item, _value, _time);
                Node *q=first;
                Node *r=NULL;
                int a=0;
                while (time(p->time,q->time)){
                    r=q;
                    q=q->next;
                    a++;
                    if(q==NULL)
                        break;
                }
                if(a!=0){
                    p->next=q;
                    r->next=p;
                }
                else{
                    p->next=first;
                    first=p;
                }
            }
        }
    }
    void display() {
        Node *p=first;
        while(p!=NULL){
            cout<<p->item<<" "<<p->value<<" "<<p->time<<endl;
            p=p->next;
        }
    }
    void erase() {
        Node *p=first;
        first=first->next;
        delete p;
    }
    void clearAll() {
        while(first!=NULL)
            erase();
    }
    void sort(Mode _mode = DEFAULT) {
        
    }
     void summary() {}
};
int main(int argc, char const *argv[])
{
Account account(TIME);
account.insert("apple", 100, "09/09/21");
account.insert("carrot", 30, "09/09/22");
account.insert("box", 80, "09/09/23");
account.insert("erasers", 1000, "09/09/24");
account.display(); cout << endl;
return 0;
}
bool check(string a,string b){
    int la=a.length(),lb=b.length(),l;
    if(la>lb)
        l=lb;
    else
        l=la;
    for(int c=0;c<l;c++){
        if(a[c]>b[c])
            return true;
        else if(a[c]<b[c])
            return false;
    }
    if(la>=lb)
        return true;
    else
        return false;
}
bool time(string a,string b){
    int daya=a[0]*10+a[1]+a[3]*1000+a[4]*100+a[6]*100000+a[7]*10000;
    int dayb=b[0]*10+b[1]+b[3]*1000+b[4]*100+b[6]*100000+b[7]*10000;
    return daya>=dayb?true:false;
}
