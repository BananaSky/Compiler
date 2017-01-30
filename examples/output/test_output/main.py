from __future__ import absolute_import
from __future__ import division
from __future__ import print_function
from __future__ import unicode_literals
from past.utils import old_div
from sys import * 
from string import * 
import random as rd 
from functions import * 
dictionary = dict() 
iterations = 0 
interactive = False 
moveAhead = 0 
quit = False 
seed = rd.randint(0,1000000) 
def usage (): 
    """rint out information regarding how to use this particular program."""  
def loadIntoDictionary (argv,dictionary): 
    """arse the argv array to a dictionary of strings->strings or 
    
        strings->string arrays. We assume all flags begin with a hyphen and all
    
        arguments to flags do not. So if we see -abc 1 2 3 then in the 
    
        dictionary we will get: dict['abc'] = ['1','2','3']
    
        """
    """
        limit = len(argv)
    
        i = 0
    
        while i < limit:
    
            if argv[i].startswith('-'):
    
                j = i+1
    
                temp = []
    
                while j < limit and not argv[j].startswith('-'):
    
                    temp.append(argv[j])
    
                    j += 1
    
    end
                if len(temp) == 1:
    
                    dictionary[argv[i]] = temp[0]
    
    end
                elif len(temp) > 1:
    
                    dictionary[argv[i]] = temp
    
    end
                else:
    
                    print ('ERROR: Every input beginning with '+
    
                    '"-" should take at least one argument. "'+
    
                    argv[i]+'". Has no such argument.\n')
    
                    usage()
    
                    sys.exit()
    
    end
                i = j-1
    
    end
            i += 1
    
    end
        return dictionary
    
        """  
def parseInput (argv): 
    """This is important for if you're interacting with the program through"""
    """the python interpreter or something. Don't ask me.""" 
    """
        if argv is None:
    
            argv = sys.argv
    
    end
        #User SOS: Check for help.
    
        #If you want to print help and exit if no arguments are given then 
    
        #add the condition "or len(argv)==1"
    
        if '-h' in argv or '-help' in argv:
    
            print '\nUser SOS'
    
            usage()
    
            sys.exit(2)
    
    end
        #Initialize dictionary
    
        dictionary = dict()
    
        #Check for a config file. Format it if found.
    
        if '-config' in argv:
    
            temp = argv.index('-config')+1
    
            try: #Try to open the file.
    
                f = open(argv[temp], 'r')
    
    end
            except IOError as e:
    
                print ('ERROR: Argument following --config should be a file. Could not open "'+str(argv[temp])+'" file does not exist.\n')
    
                usage()
    
                sys.exit()
    
    end
            contents = f.read()
    
            f.close()
    
            #Format the file, converting line breaks to blank spaces and 
    
            #then creating an array of strings.
    
            contents = contents.replace("\n",' ')
    
            contents = contents.strip()
    
            contents = contents.split(' ')
    
            #Add contents to the dictionary
    
            dictionary = loadIntoDictionary(contents, dictionary)
    
    end
        #Next, add in command line options. Anything beginning with a hyphen, 
    
        #if it's already in the dictionary, replace the value in the dict with 
    
        #the command line args.
    
        return loadIntoDictionary(argv, dictionary)
    
        """  
def checkForInput (quit,interactive,moveAhead): 
    """
        global wordlist
    
        while True:
    
            inStr = raw_input('Waiting on user input... (Type: h for help)\n>')
    
            if inStr == 'q' or inStr == 'quit':
    
                quit = True; break
    
    end
            elif inStr == '#' or inStr == 'num':
    
                temp=raw_input('Enter the number of generations to advance.\n>')
    
                moveAhead = int(temp); break
    
    end
            elif inStr == 'f' or inStr == 'finish':
    
                interactive = False; break
    
    end
            elif inStr == 'l' or inStr == 'limit':
    
                temp=raw_input('Enter the new word limit.\n>')
    
                global sentenceLengthLimit
    
                sentenceLengthLimit = int(temp)
    
    end
            elif inStr == 'd':
    
                wordlist.getSentenceDeterministic()
    
    end
            elif inStr == 'w':
    
                wordlist.getSentenceWeighted()
    
    end
            elif inStr == 'u':
    
                wordlist.getSentenceUniform()
    
    end
            else:
    
    end
        return quit, interactive, moveAhead
    
        """  