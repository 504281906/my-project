using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Ex10
{
    public class Card
    {
        public readonly Rank rank;
        public readonly Suit suit;
    
        private Card()
        {
            
        }

        public Card(Suit newSuit, Rank newRank)
        {
            suit = newSuit;
            rank = newRank;
        }

        public String ToString()
        {
            return "The " + rank + " of " + suit + "s";
        }
    }
}
