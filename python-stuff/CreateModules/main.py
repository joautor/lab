import mymodule

#print(myfunction()) #error!
print(mymodule.myfunction())


from mymodule import myfunction

print(myfunction())


#from mysample import foo.foofunc

#foofunc()



#open using 'with'

with open('monitored.txt', 'r') as f:
    for service in f:
        print(service, end='')

to_monitor = ('httpd', 'dovecot', 'postfix')

#existing file will be overwritten
with open('monitored_new.txt', 'w') as f:
    for service in to_monitor:
        f.write(service)
        f.write('\n')

#open to append
with open('monitored.log', 'a') as f:
    f.write(f'Monitored: {to_monitor}\n')

