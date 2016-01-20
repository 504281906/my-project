using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Ex10
{
    public class Deck
    {
        private Card[] cards;
    
        public Deck()
        {
            cards = new Card[52];
            for (int suitVal = 0; suitVal < 4; suitVal++) {
                for (int rankVal = 1; rankVal < 14; rankVal++) {
                    cards[suitVal * 13 + rankVal - 1] = new Card((Suit)suitVal, (Rank)rankVal);
                }
            }
        }

        public Card GetCard(int cardNum)
        {
            if (cardNum >= 0 && cardNum <= 51)
            {
                return cards[cardNum];
            }
            else {
                throw (new System.ArgumentOutOfRangeException("cardNum", cardNum, "Value must be between 0 and 51."));
            }
        }

        public void Shuffle()
        {
            Random ran = new Random(unchecked((int)DateTime.Now.Ticks));
            Card[] a = new Card[52];
            int l = 51;
            for (int i = 0; i < 52; i++) {
                int k = ran.Next(l);
                a[i] = cards[k];
                cards[k] = cards[l];
                l--;
            }
            a.CopyTo(cards, 0);
        }
    }
}
