
class LogEntry(object):
    def __init__(self, line):
        self.line = line
        self.info = line.split(' ', 5)

    def printline(self):
        print(self.line)
        for entry in self.info:
            print(entry)
        print()

    def logIt(self, s):
        print(f'{s}')


s = 'Mar 26 15:17:01 steve CRON[13135]: (root) CMD ( cd /&& run-parts --report /etc/cron.hourly)'

log = LogEntry(s)
log.printline()

log.logIt("Hello World!")


class Notification(object):
    #items = [], its like static variable in C++

    def __init__(self, user, message):
        self.user = user
        self.message = message
        self.items = []

    def send_message(self):
        print('Message sent to {}: {}'. format(self.user, self.message))

    def change_user(self, user):
        self.user = user

n = Notification('joe', 'The message.')
m = Notification('jane', 'Another message')

n.send_message()
m.send_message()
m.change_user('bob')
m.send_message()


print(m.items)
m.items.append('some item')
print('n items? ' + str(n.items))



# Inheritance #

class Process(object):
    def __init__(self):
        print('init Process')

    def process_function(self):
        return "process_function"

class Client(Process):
    def __init__(self):
        print('init Client')

    def process_function(self):
        return "client_funtion"

class Server(Process):
    def __init__(self):
        print('init Server')

    def process_function(self):
        result = super(Server,self).process_function()
        return result + ", server_functon"

class BackgroundProcess(Process):
    pass

p = Process()
c = Client()
s = Server()
b = BackgroundProcess()


processes = [p, c, s, b]

print()
for m in processes:
    print(m.process_function())
