import doctest
def task(str='1.txt'):
	"""           '
	>>> f=open("1.txt","w")
	>>> b=f.write(" 1          1\\n 1 1")
	>>> f.close()
	>>> task()
	1.0
	>>> f=open("1.txt","w")
	>>> b=f.write("1 1\\n\\n k1")
	>>> f.close()
	>>> task()
	'Bad File'
	>>> task('\t f  ghfghfghfghfghfghfhgffvh')
	'File not found'

	"""
	try:
		f=open(str)
		n=0
		s=0.
		while line:=f.readline():#for line in f:
			line=line.split();i=0
			while(i<len(line)):#for x in line.split():
				s+=int(line[i])
				n+=1;i+=1
		s/=n
		return s
	except ValueError:
		return "Bad File"
	except FileNotFoundError:
		return "File not found"
	except ZeroDivisionError:
		return "Empty file"
def main():       
	print(task())
#main() 
doctest.testmod()

