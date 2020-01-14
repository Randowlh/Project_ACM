
import requests
import time
import sys
status_url = 'http://acm.hdu.edu.cn/status.php'
submit_url = 'http://acm.hdu.edu.cn/submit.php'
login_url = 'http://acm.hdu.edu.cn/userloginex.php'
homepage_url = 'http://acm.hdu.edu.cn/'
language = {}
language['G++'] = 1
language['GCC'] = 2
language['C++'] = 3
language['C'] = 4
language['Pascal'] = 5
language['Java'] = 6
language['C#'] = 7
file_data = []
previous_runid = ''
greater = 'Time Limit Exceeded'
less = 'Output Limit Exceeded'
equal = 'Wrong Answer'
username = 'your username'
userpass = 'your password'
template_input_data = '''
#include <cstdio>
#include <cstdlib>
char buffer[0x10000];//64KB
// Wrong Answer
void equal(void)
{
	printf("www.hoxily.com\\n");
	exit(0);
}
// OLE
void less(void)
{
	while (true)
	{
		fwrite(buffer, sizeof(char), sizeof(buffer), stdout);
	}
}
// TLE
void greater(void)
{
	while (true)
	{
	}
}
int main(void)
{
	int ch;
	int count = 0;
	while ((ch = getchar()) != EOF)
	{
		if (ch < 0)
		{
			ch = ch + 256;
		}
		if (count == skip)
		{
			if (ch == guess)
			{
				equal();
			}
			else if (ch < guess)
			{
				less();
			}
			else
			{
				greater();
			}
		}
		count++;
	}
	return 0;
}
'''
template_input_length = '''
#include <cstdio>
#include <cstdlib>
#define MAXLEN 0x7fffffff
#define MINLEN 0
char buffer[0x10000];//64KB
// Wrong Answer
void equal(void)
{
	printf("www.hoxily.com\\n");
	exit(0);
}
// OLE
void less(void)
{
	while (true)
	{
		fwrite(buffer, sizeof(char), sizeof(buffer), stdout);
	}
}
// TLE
void greater(void)
{
	while (true)
	{
	}
}
int main(void)
{
	int ch;
	int count = 0;
	while ((ch = getchar()) != EOF)
	{
		count++;
	}
	if (count < guess)
	{
		less();
	}
	else if (count == guess)
	{
		equal();
	}
	else
	{
		greater();
	}
	return 0;
}
'''
cookies = {'exesubmitlang':'0', 'CNZZDATA1254072405': '965477099-1421749361-|1427515514'}
pid = 1000
def login(referer):
    global cookies
    headers = {'referer':referer, 'user-agent':'Mozilla/5.0 (Windows NT 6.3; WOW64; rv:36.0) Gecko/20100101 Firefox/36.0'}
    r = requests.post(login_url, params={'action':'login'}, data={'username':username,'userpass':userpass, 'login':'Sign+In'}, headers = headers, cookies=cookies)
    if r.cookies.get('PHPSESSID') is not None:
        cookies['PHPSESSID'] = r.cookies.get('PHPSESSID')
    #print(repr(cookies))
def test_length_submit(guess):
    usercode = 'int guess = ' + str(guess) + ';\r\n' + template_input_length
    return test_submit(usercode)
def find_input_length():
    print('GUESS', 'RESULT')
    guess = 1
    left = 0
    while True:
        result = test_length_submit(guess)
        print(guess, result)
        if result == 'lt':
            break
        else:
            left = guess
            guess = guess * 2
    print('LEFT', 'RIGHT', 'GUESS', 'RESULT')
    right = guess
    while left <= right:
        guess = (left + right) // 2
        result = test_length_submit(guess)
        print(left, right, guess, result)
        if result == 'eq':
            print('length =', guess)
            break
        elif result == 'gt':
            left = guess + 1
        elif result == 'lt':
            right = guess - 1
    return guess
 
def test_submit(usercode):
    global cookies
    headers = {'referer':'http://acm.hdu.edu.cn/showproblem.php?pid=' + str(pid), 'user-agent':'Mozilla/5.0 (Windows NT 6.3; WOW64; rv:36.0) Gecko/20100101 Firefox/36.0'}
    r = requests.get(submit_url, params={'pid':pid}, allow_redirects=False, cookies=cookies, headers=headers)
    if r.cookies.get('PHPSESSID') is not None:
        cookies['PHPSESSID'] = r.cookies.get('PHPSESSID')
    #print(repr(cookies))
    if r.status_code == 302:
        # need login
        login(r.url)
    r = requests.post(submit_url, params={'action':'submit'}, data={'check':0, 'problemid':pid, 'language':language['C++']-1, 'usercode':usercode}, allow_redirects=False, cookies = cookies, headers=headers)
    if r.cookies.get('PHPSESSID') is not None:
        cookies['PHPSESSID'] = r.cookies.get('PHPSESSID')
    #print(repr(cookies))
    # if r.status_code != 302:
        # raise Exception(r)
    # else:
    global previous_runid
    while True:
        time.sleep(1)
        r = requests.get(status_url, params={'user':username, 'lang':0, 'status':0}, headers=headers,cookies=cookies)
        text = r.text
        try:
            index = text.index('tr align=center')
        except ValueError:
            # server is busy so that return something else.
            time.sleep(5)
            continue
        index = text.index('px>', index)
        index += len('px>')
        endIndex = text.index('</td>', index)
        runid = text[index:endIndex]
        if runid == previous_runid: # submit failed
            return test_submit(usercode)
        index = text.index('green>', index)
        index = index + len('green>')
        endIndex = text.index('</font>', index)
        status = text[index: endIndex]
        if 'Queuing' in status:
            continue
        elif 'Compiling' in status:
            continue
        elif 'Running' in status:
            continue
        elif less in status:
            previous_runid = runid
            return 'lt'
        elif greater in status:
            previous_runid = runid
            return 'gt'
        elif equal in status:
            previous_runid = runid
            return 'eq'
        else:
            raise Exception('unknow judge status: ' + status)
def test_data_submit(skip, guess):
    usercode = 'int guess = ' + str(guess) + ';\r\n'
    usercode = usercode + 'int skip = ' + str(skip) + ';\r\n'
    usercode = usercode + template_input_data
    return test_submit(usercode)
def find_input_data():
    length = find_input_length()
    print('LEFT', 'RIGHT', 'SKIP', 'GUESS', 'RESULT')
    for skip in range(length):
        left = 0
        right = 255
        while left <= right:
            guess = (left + right) // 2
            result = test_data_submit(skip, guess)
            print(left, right, skip, guess, result)
            if result == 'eq':
                file_data.append(guess)
                print(repr(file_data))
                break
            elif result == 'lt':
                right = guess -1
            elif result == 'gt':
                left = guess + 1
        if left > right:
            file_data.append('UNKNOWN')
    return file_data
if len(sys.argv) == 1:
    print('usage:\ndiginput.py <pid> <username> <userpass>')
    sys.exit(1)
else:
    pid = int(sys.argv[1])
    username = sys.argv[2]
    userpass = sys.argv[3]
    find_input_data()
