import re
from flask import Flask, request
import telegram
from telebot.credentials import bot_token, bot_user_name, URL
from time import sleep
from telebot.web import get_alert
global bot
global TOKEN
TOKEN = bot_token
bot = telegram.Bot(token=TOKEN)

app = Flask(__name__)


@app.route('/{}'.format(TOKEN), methods=['POST'])

def respond():

   update = telegram.Update.de_json(request.get_json(force=True), bot)

   chat_id = update.message.chat.id
   msg_id = update.message.message_id

   # Telegram understands UTF-8, so encode text for unicode compatibility
   text = update.message.text.encode('utf-8').decode()

   print("got text message :", text)
   reply = get_alert()
   bot.sendMessage(chat_id=chat_id, text=reply, reply_to_message_id=msg_id)


@app.route('/set_webhook', methods=['GET', 'POST'])
def set_webhook():
   s = bot.setWebhook('{URL}{HOOK}'.format(URL=URL, HOOK=TOKEN))
   if s:
       return "webhook setup chill vmro"
   else:
       return "webhook setup failed, kat gya"


@app.route('/')
def index():
   return 'Chal gya vro, pawry kro'



if __name__ == '__main__':
   app.run(threaded=True)
