# 6.0001/6.00 Problem Set 5 - RSS Feed Filter
# Name:
# Collaborators:
# Time:

import feedparser
import string
import time
import threading
from project_util import translate_html
from mtTkinter import *
from datetime import datetime
import pytz


#-----------------------------------------------------------------------

#======================
# Code for retrieving and parsing
# Google and Yahoo News feeds
# Do not change this code
#======================

def process(url):
    """
    Fetches news items from the rss url and parses them.
    Returns a list of NewsStory-s.
    """
    feed = feedparser.parse(url)
    entries = feed.entries
    ret = []
    for entry in entries:
        guid = entry.guid
        title = translate_html(entry.title)
        link = entry.link
        description = translate_html(entry.description)
        pubdate = translate_html(entry.published)

        try:
            pubdate = datetime.strptime(pubdate, "%a, %d %b %Y %H:%M:%S %Z")
            pubdate.replace(tzinfo=pytz.timezone("GMT"))
          #  pubdate = pubdate.astimezone(pytz.timezone('EST'))
          #  pubdate.replace(tzinfo=None)
        except ValueError:
            pubdate = datetime.strptime(pubdate, "%a, %d %b %Y %H:%M:%S %z")

        newsStory = NewsStory(guid, title, description, link, pubdate)
        ret.append(newsStory)
    return ret

#======================
# Data structure design
#======================

# Problem 1

class NewsStory():
    def __init__(self, guid=None, title=None, description=None, link=None, pubdate=None):
        self.guid = guid
        self.title = title
        self.description = description
        self.link = link
        self.pubdate = pubdate

    def get_guid(self):
        return self.guid
    
    def get_title(self):
        return self.title

    def get_description(self):
        return self.description
    
    def get_link(self):
        return self.link
    
    def get_pubdate(self):
        # datetime is immutable
        return self.pubdate




#======================
# Triggers
#======================

class Trigger(object):
    def evaluate(self, story):
        """
        Returns True if an alert should be generated
        for the given news item, or False otherwise.
        """
        # DO NOT CHANGE THIS!
        raise NotImplementedError

# PHRASE TRIGGERS

# Problem 2
class PhrasesTrigger(Trigger):
    def __init__(self, phrase):
        self.phrase = phrase.lower()
    
    def is_phrase_in(self, text):
        fire = False

        # 为了减少代码量，使用了列表解析
        phrase_string = ''.join([char if char not in string.punctuation else ' ' for char in self.phrase])
        text_string = ''.join([char if char not in string.punctuation else ' ' for char in text.lower()])
        phrase_list = phrase_string.split()
        text_list = text_string.split()
        
        for index in range(len(text_list) - len(phrase_list) + 1):
            if text_list[index] == phrase_list[0]:
                if phrase_list == text_list[index:index+len(phrase_list)]:
                    fire = True
                    break

        return fire
                        

# Problem 3
class TitleTrigger(PhrasesTrigger):
    def __init__(self, phrase):
        super().__init__(phrase)

    def evaluate(self, story):
        return self.is_phrase_in(story.get_title())

# Problem 4
class DescriptionTrigger(PhrasesTrigger):
    def __init__(self, phrase):
        super().__init__(phrase)
    
    def evaluate(self, story):
        return self.is_phrase_in(story.get_description())

# TIME TRIGGERS

# Problem 5
# 自己引入了一个calendar库构造月份对应数字的词典
import calendar
class TimeTrigger(Trigger):
    # Constructor:
#        Input: Time has to be in EST and in the format of "%d %b %Y %H:%M:%S".
#        Convert time from string to a datetime before saving it as an attribute.
    def __init__(self, Time):
        time_list = Time.replace(':', ' ').split()
        keys = [calendar.month_abbr[index] for index in range(1,13)]
        values = [i for i in range(1,13)]
        Month_Num = dict(zip(keys, values))

        self.Time = datetime(year=int(time_list[2]), month=Month_Num[time_list[1]], day=int(time_list[0]), hour=int(time_list[3]), minute=int(time_list[4]), second=int(time_list[5]))


# Problem 6
# TODO: BeforeTrigger and AfterTrigger
class BeforeTrigger(TimeTrigger):
    def __init__(self, Time):
        super().__init__(Time)
    
    def evaluate(self, story):
        return story.get_pubdate() < self.Time

class AfterTrigger(TimeTrigger):
    def __init__(self, Time):
        super().__init__(Time)
    
    def evaluate(self, story):
        return story.get_pubdate() > self.Time

# COMPOSITE TRIGGERS

# Problem 7
class NotTrigger(Trigger):
    def __init__(self, other_Trigger):
        self.other_Trigger = other_Trigger

    def evaluate(self, story):
        return not (self.other_Trigger.evaluate(story))


# Problem 8
class AndTrigger(Trigger):
    def __init__(self, first_Trigger, second_Trigger):
        self.first_Trigger = first_Trigger
        self.second_Trigger = second_Trigger

    def evaluate(self, story):
        return (self.first_Trigger.evaluate(story) and self.second_Trigger.evaluate(story))

# Problem 9
class OrTrigger(Trigger):
    def __init__(self, first_Trigger, second_Trigger):
        self.first_Trigger = first_Trigger
        self.second_Trigger = second_Trigger

    def evaluate(self, story):
        return (self.first_Trigger.evaluate(story) or self.second_Trigger.evaluate(story))


#======================
# Filtering
#======================

# Problem 10
def filter_stories(stories, triggerlist):
    """
    Takes in a list of NewsStory instances.

    Returns: a list of only the stories for which a trigger in triggerlist fires.
    """
    # TODO: Problem 10
    # This is a placeholder
    # (we're just returning all the stories, with no filtering)
    fire_story = []
    for trigger in triggerlist:
        for story in stories:
            if trigger.evaluate(story):
                # if story not in fire_story:
                fire_story.append(story)

    return fire_story



#======================
# User-Specified Triggers
#======================
# Problem 11
def read_trigger_config(filename):
    """
    filename: the name of a trigger configuration file

    Returns: a list of trigger objects specified by the trigger configuration
        file.
    """
    # We give you the code to read in the file and eliminate blank lines and
    # comments. You don't need to know how it works for now!
    trigger_file = open(filename, 'r')
    lines = []
    for line in trigger_file:
        line = line.rstrip()
        if not (len(line) == 0 or line.startswith('//')):
            lines.append(line)

    # TODO: Problem 11
    # line is the list of lines that you need to parse and for which you need
    # to build triggers

    print(lines) # for now, print it so you see what it contains!

    trigger_list = []
    for i in range(6):
        print(i)
        line_list = lines[i].split(',')
        content = line_list[2]
        type_trigger = line_list[1]
        if type_trigger == 'TITLE':
            tmp = TitleTrigger(content)
        elif type_trigger == 'DESCRIPTION':
            tmp = DescriptionTrigger(content)
        if type_trigger == 'AFTER':
            tmp = AfterTrigger(content)
        elif type_trigger == 'BEFORE':
            tmp = BeforeTrigger(content)
        # elif type_trigger == 'NOT':
        #     tmp = NotTrigger(content)
        elif i == 4:
            tmp = AndTrigger(trigger_list[1], trigger_list[2])
        elif i == 5:
            tmp = AndTrigger(trigger_list[0], trigger_list[3])
        # elif type_trigger == 'OR':
        #     tmp = OrTrigger(content, line_list[3])
        
        trigger_list.append(tmp)
    
    trigger_list.append(AndTrigger(trigger_list[-2], trigger_list[-1]))
    
    return trigger_list





SLEEPTIME = 120 #seconds -- how often we poll

def main_thread(master):
    # A sample trigger list - you might need to change the phrases to correspond
    # to what is currently in the news
    try:
        t1 = TitleTrigger("election")
        t2 = DescriptionTrigger("Trump")
        t3 = DescriptionTrigger("Clinton")
        t4 = AndTrigger(t2, t3)
        triggerlist = [t1, t4]

        # Problem 11

################################################################################## ps5_test已经通过，但是运行后没有切出任何news

        # TODO: After implementing read_trigger_config, uncomment this line 
        triggerlist = read_trigger_config('./Pset5/triggers.txt')
        
        # HELPER CODE - you don't need to understand this!
        # Draws the popup window that displays the filtered stories
        # Retrieves and filters the stories from the RSS feeds
        frame = Frame(master)
        frame.pack(side=BOTTOM)
        scrollbar = Scrollbar(master)
        scrollbar.pack(side=RIGHT,fill=Y)

        t = "Google & Yahoo Top News"
        title = StringVar()
        title.set(t)
        ttl = Label(master, textvariable=title, font=("Helvetica", 18))
        ttl.pack(side=TOP)
        cont = Text(master, font=("Helvetica",14), yscrollcommand=scrollbar.set)
        cont.pack(side=BOTTOM)
        cont.tag_config("title", justify='center')
        button = Button(frame, text="Exit", command=root.destroy)
        button.pack(side=BOTTOM)
        guidShown = []
        def get_cont(newstory):
            if newstory.get_guid() not in guidShown:
                cont.insert(END, newstory.get_title()+"\n", "title")
                cont.insert(END, "\n---------------------------------------------------------------\n", "title")
                cont.insert(END, newstory.get_description())
                cont.insert(END, "\n*********************************************************************\n", "title")
                guidShown.append(newstory.get_guid())

        while True:

            print("Polling . . .", end=' ')
            # Get stories from Google's Top Stories RSS news feed
            stories = process("http://news.google.com/news?output=rss")

            # Get stories from Yahoo's Top Stories RSS news feed
            stories.extend(process("http://news.yahoo.com/rss/topstories"))

            stories = filter_stories(stories, triggerlist)

            list(map(get_cont, stories))
            scrollbar.config(command=cont.yview)


            print("Sleeping...")
            time.sleep(SLEEPTIME)

    except Exception as e:
        print(e)


if __name__ == '__main__':
    root = Tk()
    root.title("Some RSS parser")
    t = threading.Thread(target=main_thread, args=(root,))
    t.start()
    root.mainloop()
