import requests
from bs4 import BeautifulSoup
import time

SearchURL = "https://coinmarketcap.com/currencies/ethereum/"

def Search_Tracking_Price():
    Search_Page = requests.get(SearchURL)
    soup = BeautifulSoup(Search_Page.content, "html.parser")
    title = soup.find(class_="sc-1q9q90x-0 jCInrl h1").get_text()
    print(title)
    try:
        price = soup.find("div", class_="priceValue").get_text()
        # print(price)
    except AttributeError:
        print("Error")
    convert_Price = price[1:9].replace(",","").replace(".","")
    int_convert_Price = int(convert_Price)
    print(convert_Price)

    if(int_convert_Price < 350000):
        Notify()

def Notify():
    print("通知")
    Line_Notify_Token = ""#line token ID
    Line_Notify_Api = "https://notify-api.line.me/api/notify"
    headers = {"Authorization": f"Bearer {Line_Notify_Token}"}
    data = {"message": SearchURL}
    requests.post(Line_Notify_Api, headers=headers, data=data)

while(True):
    print("Tracking")
    time.sleep(5)
    Search_Tracking_Price()
# Search_Tracking_Price()