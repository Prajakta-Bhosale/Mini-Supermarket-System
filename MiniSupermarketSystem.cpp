#include<iostream>;
#include<string>;
#include<fstream>;
#include<queue>;
using namespace std;

static int count;
queue &lt;string&gt; que;
void show(queue &lt;string&gt; g)
{

while(!g.empty())
{
cout&lt;&lt;g.front()&lt;&lt;endl;
g.pop();
}

}
class superMarket
{
char name[30];
float cost;
long long int contactNo;
int Order[6][4];
public:

superMarket()
{
cost = 0;

Order[0][0]=600;
Order[0][1]=500;
Order[0][2]=900;
Order[0][3]=1000;
Order[1][0]=1000;
Order[1][1]=500;
Order[1][2]=400;
Order[1][3]=300;
Order[2][0]=500;
Order[2][1]=100;
Order[2][2]=150;
Order[2][3]=100;
Order[3][0]=1000;
Order[3][1]=500;
Order[3][2]=400;
Order[3][3]=300;
Order[4][0]=60;
Order[4][1]=50;
Order[4][2]=40;
Order[4][3]=30;
Order[5][0]=200;
Order[5][1]=100;
Order[5][2]=40;
Order[5][3]=20;

}

void acceptOrder();

void Display();
int acceptItem( int );

};
void superMarket::Display()
{
cout&lt;&lt;&quot;\n&quot;&lt;&lt;name&lt;&lt;&quot;\t\t&quot;&lt;&lt;contactNo&lt;&lt;endl;

}

void superMarket:: acceptOrder()
{ char z;
cost=0;
int item,Quantity,Brand;
cout&lt;&lt;&quot;\n-----------------------------------------------------------------------

\n&quot;;

cout&lt;&lt;&quot;\nEnter name:&quot;;
cin&gt;&gt;name;
cout&lt;&lt;&quot;\nEnter contact no:&quot;;
cin&gt;&gt;contactNo;
do
{
cout&lt;&lt;&quot;Sr No \t\t List of items \n&quot;;
cout&lt;&lt;&quot;\n 1 \t\t Shirts \n 2 \t\t Shoes \n 3 \t\t Accessories \n 4

\t\t Jeans/Trousers \n 5 \t\t Cosmetics \n 6 \t\t Eatables \n&quot;;
cout&lt;&lt;&quot;Enter ur choice:&quot;;
cin&gt;&gt;item;
que.push(name);
Brand=acceptItem(item);
cout&lt;&lt;&quot;Enter quantity:&quot;;

cin&gt;&gt;Quantity;
cost=(Order[item-1][Brand-1])*Quantity+cost;
cout&lt;&lt;&quot;Total Cost:&quot;&lt;&lt;cost;

cout&lt;&lt;&quot;\nAny other choice?(y/n):&quot;;
cin&gt;&gt;z;
while(z!=&#39;y&#39;&amp;&amp;z!=&#39;Y&#39;&amp;&amp;z!=&#39;n&#39;&amp;&amp;z!=&#39;N&#39;)
{ cout&lt;&lt;&quot;\nEnter correct choice&quot;;
cin&gt;&gt;z;
}
}while(z==&#39;y&#39; ||z==&#39;Y&#39;);
}
int superMarket::acceptItem( int item)
{ int brand;
switch(item)
{
case 1: cout&lt;&lt;&quot;\n Brand \t\t Cost&quot;;
cout&lt;&lt;&quot; \n 1-Cotton King \t\t 600 \n 2-Raymond \t\t

500 \n 3-Peter England \t 900 \n 4-Van Heusen \t\t 1000\nEnter ur choice\n&quot;;

cin&gt;&gt;brand;
return brand;

case 2: cout&lt;&lt;&quot;\n Brand \t\t Cost&quot;;
cout&lt;&lt;&quot; \n 1-Puma \t\t 1000 \n 2-Bata \t\t 500 \n 3-

Flite \t\t 400 \n 4-HiFly \t\t 300\n Enter ur choice\n&quot;;
cin&gt;&gt;brand;
return brand;
case 3: cout&lt;&lt;&quot;\n Brand \t\t Cost&quot;;
cout&lt;&lt;&quot; \n 1-Watch \t\t 500 \n 2-Earrings \t\t 100 \n

3-Perfumes \t\t 150 \n 4-bracelates \t\t 100\n Enter ur choice\n&quot;;
cin&gt;&gt;brand;

return brand;
case 4: cout&lt;&lt;&quot;\n Brand \t\t Cost&quot;;
cout&lt;&lt;&quot; \n 1-Pepe Jeans \t\t 1000 \n 2-Levi&#39;s \t\t 500

\n 3-Wrangler \t\t 400 \n 4-Lee \t\t 300\n Enter ur choice\n&quot;;
cin&gt;&gt;brand;
return brand;
case 5: cout&lt;&lt;&quot;\n Brand \t\t Cost&quot;;
cout&lt;&lt;&quot; \n 1-Powder \t\t 60 \n 2-Creams \t\t 50 \n 3-

Facewash \t\t 40 \n 4-Soap \t\t 30\n Enter ur choice\n&quot;;
cin&gt;&gt;brand;
return brand;
case 6: cout&lt;&lt;&quot;\n Brand \t\t Cost&quot;;
cout&lt;&lt;&quot; \n 1-Pizza \t\t 200 \n 2-Burger \t\t 100 \n 3-

ice creams \t\t 40 \n 4-Cadbury \t\t 20\n Enter ur choice\n&quot;;
cin&gt;&gt;brand;
return brand;
}
}

int main()
{

superMarket s;
int repeat,choice;
char ch;
do
{
cout&lt;&lt;&quot;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n&quot;;
cout&lt;&lt;&quot;\t\t\t\tSUPERMARKET\n&quot;;

cout&lt;&lt;&quot;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n&quot;;
cout&lt;&lt;&quot;\t\t\t 1.Accept Order 2-serve order 3-Display contents from file Market \n Enter ur
choice&quot;;
cin&gt;&gt;choice;
switch(choice)
{
case 1:{
ofstream out;

out.open(&quot;market.dat&quot;,ios::binary | ios::app)
do
{
s.acceptOrder();
out.write((char *)&amp;s,sizeof(s));
cout&lt;&lt;&quot;customer&#39;s details are written successfully to the File named
market!!!&quot;;
cout&lt;&lt;&quot;\nPress 1 to continue&quot;;
cin&gt;&gt;repeat;
}while(repeat==1);
out.close();
break;
}
case 2:{

cout&lt;&lt;&quot;\norder is served for:&quot;&lt;&lt;que.front()&lt;&lt;endl;
que.pop();
cout&lt;&lt;&quot;\nlist of orders which are not served:\n&quot;;
cout&lt;&lt;&quot;\nNAME \n&quot;;
show(que);
break;
}

case 3:{ cout&lt;&lt;&quot;\nNAME \t\t CONTACT NO. \n&quot;;
ifstream in;
in.open(&quot;market.dat&quot;,ios::binary);
while(in)
{
in.read((char*)&amp;s,sizeof(s));
if(in.eof()!=0)
break;
s.Display();
}
in.close();
}
break;

}
cout&lt;&lt;&quot;\nany other operation?(y/n)\n&quot;;
cin&gt;&gt;ch;
}while(ch==&#39;y&#39;||ch==&#39;Y&#39;);
return 0;
}
