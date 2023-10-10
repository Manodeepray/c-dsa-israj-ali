def killYourself(person):
    print(person,"killed themselves")
    del person
    
    exit
    
person=str(input("enter the name of the person you want to killthemselves"))

option=str(input("are you sure?Y/N"))
if(option=="y"):
    killYourself(person)
