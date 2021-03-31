#pragma once

#include  <stdlib.h>  
#include  <malloc.h>
#include  <string>
#include  <iostream>
using   namespace  std;
class  stringBuffer {
public:
	stringBuffer()
	{
		initiatiate();

	}
	stringBuffer(char *  str)
	{
		initiatiate();
		append(str);
	}
	void  initiatiate()
	{
		capacity = 0;
		length = 0;
		increment = 2;
		buffer = NULL;
	}
	stringBuffer(string   &  str)
	{
		initiatiate();
		append(str.c_str());
	}
	stringBuffer(const  stringBuffer  & value)
	{
		if (this == &value)
		{
			return;
		}
		initiatiate();
		append(value.getBuffer());
	}
	char *  getBuffer()  const
	{
		if (length  >   0)
			return  buffer;
		else
			return  NULL;
	}
	~stringBuffer()
	{
		delete[] buffer;
		length = 0;
		capacity = 0;
	}
	inline  int  append(const   char *  str)
	{
		int  str_len = strlen(str);
		if (str_len <= 0)
		{
			return   -1;
		}
		char *  temp = trim_buffer(str_len);
		if (temp == NULL)
		{
			return   -2;
		}
		strcpy(temp, str);
		length = length + str_len;
		return  str_len;

	}
	inline  int  new_capacity(int  new_size)
	{
		return  increment * (capacity + new_size);
	}
	inline  bool  is_need_extend(int  new_size)
	{
		return   (capacity - length) <= new_size * increment;
	}
	inline  char *  trim_buffer(int  str_size)
	{
		if (is_need_extend(str_size))
		{
			char *  temp;
			int  inew_capacity = new_capacity(str_size);
			temp = (char *)malloc(inew_capacity);
			if (temp == NULL)
			{
				printf(" Error the malloc return Null\n ");
				return  NULL;
			}
			capacity = inew_capacity - 1;
			memset(temp, 0, capacity + 1);
			strncpy(temp, buffer, length);
			if (buffer != NULL)
			{
				free(buffer);
			}
			buffer = temp;
		}
		return  buffer + length;
	}
	int  get_capacity()  const
	{
		return  capacity;
	}

	int  append(string &  str)
	{
		return  append(str.c_str());
	}
	const   char &   operator  [] (int  index)  const
	{
		if (index >= 0 && index < length)
		{
			return  buffer[index];
		}

	}
	char   &   operator  [] (int  index)
	{
		if (index >= 0 && index < length)
		{
			return  buffer[index];
		}
	}
	int  get_length()  const
	{
		return  length;
	}
	friend  ostream &   operator << (ostream &  os, stringBuffer &  str_buffer)
	{
		os << (char *)str_buffer.getBuffer();
		return  os;
	}
	friend stringBuffer  operator   + (const  stringBuffer &  a, const  stringBuffer  &  b)
	{
		stringBuffer temp = a;
		temp.append((char *)b.getBuffer());
		return  temp;
	}
	stringBuffer &   operator   = (const  stringBuffer &  value)
	{
		if (buffer)
		{
			free(buffer);
		}
		initiatiate();

		append(value.getBuffer());
		return   *this;
	}
private:
	int  increment;
	char *  buffer;
	int  length;
	int  capacity;
};




