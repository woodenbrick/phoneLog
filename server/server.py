#!/usr/bin/env python
import datetime
import time
from google.appengine.ext.webapp import RequestHandler
from google.appengine.ext import db
from google.appengine.ext.webapp.util import run_wsgi_app
from google.appengine.ext.webapp import WSGIApplication
from google.appengine.ext.webapp.template import render

class Record(db.Model):
    group = db.StringProperty()
    user = db.StringProperty()
    calltime = db.DateTimeProperty()
    number = db.IntegerProperty()
    
class Add(RequestHandler):
    def post(self):
        date = datetime.datetime(*time.strptime(self.request.get("date"), "%Y-%m-%dT%H:%M:%S")[0:6])
        number = int(self.request.get("number"))
        group = self.request.get("group")
        user = self.request.get("user")
        
        record = Record(group=group, calltime=date, user=user, number=number)
        record.put()
        
class Retrieve(RequestHandler):
    def get(self, group):
        records = Record.all().filter("group =", group).fetch(1000)
        self.response.headers['Content-type'] = "text/xml"
        self.response.out.write(render("numbers.xml", {"records" : records,
                                                       "group" : group}))
        
class Error(RequestHandler):
    def get(self):
        self.response.out.write("Page not found")

app = WSGIApplication(
    [
        ("/add", Add),
        ("/retrieve/(.*)", Retrieve),
        ("/.*", Error)
    ]
, debug= True
)
        
run_wsgi_app(app)
        
        
        
