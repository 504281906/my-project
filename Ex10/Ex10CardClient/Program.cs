using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Ex10;

namespace Ex10CardClient
{
    class Program
    {
        static void Main(string[] args)
        {
            Deck myDeck = new Deck();
            myDeck.Shuffle();
            for (int i = 0; i < 52; i++) {
                Card tempCard = myDeck.GetCard(i);
                Console.WriteLine(tempCard.ToString());
            }
            Console.ReadKey();
        }
    }
}
