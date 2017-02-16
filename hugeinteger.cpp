#include <iostream>
#include <cstring>
#include <string>
#include "hugeinteger.h"
using namespace std;

HugeInteger::HugeInteger()
{
	for(int i=0; i<40; i++)
		DIGITS[i]= 0;
};
HugeInteger::HugeInteger(const string& strVal)
{
	for(int i=0; i<40; i++)
                DIGITS[i]= 0;
	length = strVal.size();
	int count=0;
	for(int i=length-1; i>=0;i--)
	{
		DIGITS[count] = strVal[i]-'0';
		count++;
	}
};

HugeInteger& HugeInteger :: operator= (const HugeInteger& x)
{
	length = x.length;
	for(int i=0; i<40; i++)
                DIGITS[i]= 0;
	for(int i=0; i<40; i++)
                DIGITS[i]= x.DIGITS[i];
}

HugeInteger HugeInteger:: operator+ (const HugeInteger& x)
{
	HugeInteger sum;
	
	if (length>x.length)
	{
		sum.length=length;
		for (int i=0; i<length;i++)
		{
			sum.DIGITS[i]+= DIGITS[i]+x.DIGITS[i];
			if (sum.DIGITS[i]>=10)
			{
				if(i==sum.length-1)
					sum.length+=1;
				sum.DIGITS[i+1] += sum.DIGITS[i]/10;
				sum.DIGITS[i]    = sum.DIGITS[i]%10;
			}
		}
	}
	else
	{
		sum.length=x.length;
		for (int i=0; i<x.length; i++)
		{
			
                        sum.DIGITS[i] += DIGITS[i]+x.DIGITS[i];
                        if (sum.DIGITS[i]>=10)
                        {
				if(i==sum.length-1)
					sum.length+=1;
                                sum.DIGITS[i+1] += sum.DIGITS[i]/10;
                                sum.DIGITS[i]    = sum.DIGITS[i]%10;
                        }
                }
	}
	return sum;
};

HugeInteger HugeInteger:: operator*(const HugeInteger& x)
{
	int count=0;
	HugeInteger holder;
	HugeInteger product;
	product.length=(length+x.length-1);
	holder.length=(length+x.length-1);
	if(length>x.length)
	{
		for(int i=0;i<x.length;i++)
		{
			setZero(holder);
			for(int j=0; j<length;j++)
			{
				holder.DIGITS[j+count]+=DIGITS[j]*x.DIGITS[i];
				if (holder.DIGITS[j+count]>=10)
				{
					if ((j+count)==(holder.length-1))
					{
							holder.length+=1;
							product.length+=1;
					}
					holder.DIGITS[j+1+count] += holder.DIGITS[j+count]/10;
					holder.DIGITS[j+count]    = holder.DIGITS[j+count]%10;
				}
			}
			product=product+holder;
			count ++;
		}
	}
	else
 	{
                for(int i=0;i<length;i++)
                {
                        setZero(holder);
                        for(int j=0; j<x.length;j++)
                        {
                                holder.DIGITS[j+count]+=DIGITS[i]*x.DIGITS[j];
                                if (holder.DIGITS[j+count]>=10)
                                {
                                        if ((j+count)==(holder.length-1))
                                        {
                                                        holder.length+=1;
                                                        product.length+=1;
                                        }
                                        holder.DIGITS[j+1+count] += holder.DIGITS[j+count]/10;
                                        holder.DIGITS[j+count]    = holder.DIGITS[j+count]%10;
                                }
                        }
                        product=product+holder;
                        count ++;
                }
        }


	return product;
};

bool HugeInteger:: operator==(const HugeInteger& x) const
{
	bool value=true;
	int count=0;
	for(int i=0; i<40; i++)
	{
		if(DIGITS[i]!=x.DIGITS[i])
			count++;
	}
	if (count==0)
		value=true;
	else
		value=false;
	return (value);
};
bool HugeInteger:: operator!=(const HugeInteger& x) const
{
	return ! operator==(x);
};

bool HugeInteger:: operator>=(const HugeInteger& x) const
{
	if (length>x.length)
		return 1;
	else if (x.length>length)
		return 0;
	else
	{
		int count=0;
        	for(int i=0; i<40; i++)
        	{
                	if(DIGITS[i]!=x.DIGITS[i])
                        count++;
        	}
        	if (count==0)
                	return 1 ;
        	else
		{	
			for(int i=length; i>=0;i--)
			{
				if (DIGITS[i]>x.DIGITS[i])
					return 1;
			}
		}	
	}
	return 0;	
};

bool HugeInteger:: operator<=(const HugeInteger& x) const
{
	if(operator==(x))
		return 1;
	return ! operator>= (x);
};

void operator<<(ostream &out, const HugeInteger& x)
{
	for(int i=x.length-1; i>=0;i--)
		out<<x.DIGITS[i];
};

void operator>>(istream &in, HugeInteger& x)
{
	string temp;
	in>>temp;
	HugeInteger y(temp);
	x = y;
};

void HugeInteger::setZero(HugeInteger &x)
{
	for(int i=0; i<40; i++)
               x.DIGITS[i]= 0;
};
void HugeInteger::display()
{
	for(int i=length-1;i>=0;i--)
		cout<<DIGITS[i];
};
