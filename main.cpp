#include <iostream>
#include<queue>
using namespace std;
int g;
int p=0;
int i=0;
int f=0;
int s=0;
int dd;
int l=0;
int vv=10;
int ll=0;
class customer
{
private:
    int id;
    int arrival_time;
    int waiting_time;


public:
    customer(int a,int b);
    void setid(int n);
    void setarrival_time(int n);
    void setwaiting_time(int n);
    int getid();
    int getarrival_time();
    int getwaiting_time();
    void increment_watingtime();
    friend class server;
    friend updatearrival(int t);
};
queue <customer>q1;
queue<customer> q2;
customer::customer(int a,int b)
{
    id=a;
    arrival_time=b;
    waiting_time=0;

}
void customer::setid(int n)
{
    id=n;

}
void customer::setarrival_time(int n)
{
    arrival_time=n;

}
void customer::setwaiting_time(int n)
{
    waiting_time=n;

}
int customer::getid()
{

    return id;
}
int customer::getwaiting_time()
{

    return waiting_time;
}
void customer::increment_watingtime()
{
    waiting_time++;
}
class server
{
private:
    int operation_time;
    int repairing_time;
    string status;
    int service_time;
    int servicecompletion;
    int servicebreak;
    int breakinit;
    queue<customer> q1;
    int e;
    int w;
    int s;
public:
    int numberofcustomers()
    {

        return q1.size();
    }
    server(queue<customer> q,int a,int b,int d,string c,int s,int h,int r,int u);
    void set_status(string a);
    void set_servicecompletion(int n);
    void set_servicebreak(int n);
    string  get_status();
    bool isidle();
    bool isbusy();
    bool isdown();
    bool isblocked();
    int get_servicetime();
    void update_status(int t);
    void update_breaktime(int t);
    void update_complete(int t);
    void updatearrival(int t);
    void update_queuee(int t);
    int get_servicecompletion();
    int jjj()
    {
        if (status=="down")
        {
            return servicebreak+repairing_time;


        }
        else
        {
            return 0 ;
        }
    }
};
server server1(q1,200,50,20,"idle",80,0,80,1);
server server2(q2,300,150,30,"idle",90,60,90,0);
server::server(queue <customer>q,int a=0,int b=0,int d=0,string c="idle",int s=0,int h=0,int r=0,int u=0)
{
    q1=q;

    status=c;
    operation_time=a;
    repairing_time=b;
    service_time=d;
    servicebreak=s;
    servicecompletion=h;
    breakinit=r;
    e=u;
    w=0;
    s=0;
}
int server::get_servicecompletion()
{

    return servicecompletion;
}
void server::set_status(string a)
{
    status=a;

}
void server::update_status(int t)
{





    if(s<1)
    {

        if(t==breakinit|| (t>breakinit && t<breakinit+repairing_time))
        {
            this->set_status("down");
            s++;
        }
        else if(e==0)
        {
            if(q1.size()==4)
            {
                server1.set_status("blocked");
            }

        }
        else if(q1.empty())
        {
            this->set_status("idle");
        }

        else if(!(q1.empty()))
        {
            this->set_status("busy");
        }

    }
    else
    {
        if(t==servicebreak || (t>servicebreak && t<servicebreak+repairing_time))
        {
            this->set_status("down");
        }


        else if(t=servicebreak+repairing_time && status=="down")
        {
            if(q1.empty())
            {
                this->set_status("idle");
            }
            if(!q1.empty())
            {
                this->set_status("busy");

            }
        }
        else  if(e==0)
        {
            if(q1.size()==4)
            {
                server1.set_status("blocked");
            }

        }
        else  if(q1.empty())
        {
            this->set_status("idle");
        }

        else if(!(q1.empty()))
        {
            this->set_status("busy");
        }

    }
}
void server::set_servicebreak(int n)
{
    servicebreak=n;

}
void server::set_servicecompletion(int n)
{
    servicecompletion=n;

}
string server::get_status()
{
    return status;
}

void server::updatearrival(int t)
{

    if(i==0)
    {
        if(t==10)
        {
            customer *a=new customer(f,t);
            a->id=f;
            a->arrival_time=t;
            a->waiting_time=0;
            server1.q1.push(*a);
            f++;

            i++;
            vv=t+40;
        }


    }
    else
    {
        if((t-10)%40==0)
        {
            vv=t+40;
            if(t>=servicebreak-service_time && t<=servicebreak-service_time+repairing_time+1)
            {

                g=servicebreak+repairing_time+p*service_time;
                customer *a=new customer(f,g);
                a->id=f;
                a->arrival_time=g;
                a->waiting_time=0;
                server1.q1.push(*a);
                f++;
                p++;

            }



            else
            {
                if(!q1.empty())
                {
                    t=q1.back().arrival_time+service_time;
                    customer *a=new customer(f,t);

                    a->id=f;
                    a->arrival_time=t;
                    a->waiting_time=0;
                    server1.q1.push(*a);
                    f++;
                }
                else
                {
                    customer *a=new customer(f,t);

                    a->id=f;
                    a->arrival_time=t;
                    a->waiting_time=0;
                    server1.q1.push(*a);
                    f++;
                }
            }



        }
    }
}
void server::update_breaktime(int t)
{


    if(t==servicebreak+repairing_time)
    {
        w++;
    }
    servicebreak=breakinit+w*(operation_time+repairing_time);

}

void server::update_complete(int t)
{
    if(!q1.empty())
    {
        if(t>=servicebreak && t<servicebreak+repairing_time)
        {
            servicecompletion=servicebreak+repairing_time+service_time;


        }


        else
        {
            servicecompletion=q1.front().arrival_time+service_time;
        }





    }


}


void server::update_queuee(int t)

{

    if( !server1.q1.empty() && server1.status!="down" /*&&server1.status!="blocked"*/)
    {
        if(t==server1.servicecompletion)
        {
            if(t>=servicebreak-service_time && t<=servicebreak-service_time+repairing_time+1)
            {

                g=servicebreak+repairing_time+l*service_time;
                l++;

                server1.q1.front().arrival_time=g;
            }
            else
            {
                if(!q1.empty())
                {
                    g=q1.back().arrival_time+service_time;
                    server1.q1.front().arrival_time=g;
                }
                else
                {
                    server1.q1.front().arrival_time=t;
                }
            }

            server2.q1.push(server1.q1.front());
            server1.q1.pop();


        }
    }
    if(t==server2.servicecompletion)
    {
        if(q1.size()==4) dd=t ;
        server2.q1.pop();



    }



}



int main()
{
    for(int z=0; z<=500; z++)
    {
        server1.updatearrival(z);
        server1.update_status(z);
        server2.update_status(z);
        server1.update_breaktime(z);
        server2.update_breaktime(z);
        server1.update_complete(z);
        server2.update_complete(z);



        server2.update_queuee(z);

        cout<<z<<"  "<<vv<<"  "<<server1.numberofcustomers()<<" "<<server1.get_servicecompletion()<<"   "<<server1.jjj()<<" "<<server1.get_status()<<"    "<<server2.numberofcustomers()<<"  "<<server2.get_servicecompletion()<<"  "<<server2.jjj()<<"  "<<server2.get_status()<<endl;
    }
    return 0;
}
