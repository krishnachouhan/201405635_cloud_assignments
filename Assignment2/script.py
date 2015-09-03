oimport sys
import pdb
from mininet.net import Mininet
from mininet.node import Controller
from mininet.topo import Topo
from mininet.cli import CLI
from mininet.log import setLogLevel, info
from mininet.node import CPULimitedHost

def creating():
	X=int(sys.argv[1])
	Y=int(sys.argv[2])
	N=X*Y
	h=[]
	s=[]
	even_ips = "17.0.1."
	odd_ips="19.0.2."
	count=1
	even_count = 1
	odd_count = 1
	net = Mininet(controller = Controller)
	info ('***Adding controller\n')
	net.addController('c0')
	info ('***Adding Hosts\n')
	for i in range(N):
		if((i+1)%2 == 0):
			h.append(net.addHost("h"+str(count), ip=even_ips+str(even_count)))
			even_count = even_count + 1
			count = count + 1
		if((i+1)%2 == 1):
			h.append(net.addHost("h"+str(count), ip=odd_ips+str(odd_count)))
			odd_count = odd_count + 1
			count = count + 1
	count = 0
	info('***Adding Switches\n')
	for i in range(Y):
		s.append(net.addSwitch("s"+str(i+1)))
	info('***Adding Links\n')
	for i in range(Y):
		for j in range(X):
			obj = net.addLink(h[count], s[i])
			if count %2 ==0:
				obj.intf1.config(bw=2)
			elif count %2 ==1:
				obj.intf1.config(bw=1)
			count = count + 1
	for i in range(Y):
		for j in range(Y):
			if i<j:
				net.addLink(s[i], s[j])
	info('***Starting Net\n')
	net.Start
	info('***Running CLI\n')
	CLI(net)
	info('***Stopping Network\n')
	net.stop()
def __init__(self):
	Topo.__init__(self)
if(__name__ == "__main__"):
	setLogLevel('info')
	creating()
