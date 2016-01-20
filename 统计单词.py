# -*- coding:utf8 -*-

import io
import operator

def count(file,ignore=[',','.','?',';','!','"','\r','1','2','3','4','5','6','7','8','9','0'],f=True):
	f=open(file,"rb")
	txt=f.read()
	for i in ignore:
		txt=txt.replace(i,' ')
	txt=txt.lower()
	words=txt.split(' ')
	dic={}
	for word in words:
		if word is '':
			continue;
		if word is '\r':
			continue;
		if word in dic:
			dic[word]+=1;
		else:
			dic[word]=1;
	return dic

if __name__=='__main__':
	result=sorted(count('t1.txt').items(),key=operator.itemgetter(1),reverse=True)
	for it in result:
		print it[0],":",it[1]