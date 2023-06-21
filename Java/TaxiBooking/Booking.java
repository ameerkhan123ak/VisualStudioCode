package Java.TaxiBooking;

import java.util.*;

public class Booking
{
	public static List<Taxi> createTaxis(int n)
	{
		List<Taxi> taxis = new ArrayList<Taxi>();
		for(int i=0;i<n;i++)
		{
			Taxi t = new Taxi();
			taxis.add(t);
		}
		return taxis;
	}
	public static List<Taxi> getFreeTaxis(List<Taxi> taxis,int pickupTime,char pickupPoint)
	{
		List<Taxi> freeTaxis = new ArrayList<Taxi>();
		for(Taxi t: taxis)
		{
			if(t.freeTime <= pickupTime && (Math.abs((t.currentSpot - '0') -(pickupPoint - '0')) <= pickupTime - t.freeTime))
				freeTaxis.add(t);
		}
		return freeTaxis;
	}
	public static void bookTaxi(int customerid,char pickupPoint,char dropPoint,int pickupTime,List<Taxi> freeTaxis)
	{
		int min = 999;
		int distanceBetweenPickUpandDrop = 0;
		int earning = 0;
		int nextfreeTime = 0;
		char nextSpot = 'Z';
		Taxi bookedTaxi = null;
		String tripDetail = "";
		
		for(Taxi t: freeTaxis)
		{
			int distanceBetweenCustomerAndTaxi = Math.abs((pickupPoint - '0') - (t.currentSpot - '0')) * 15;
			if(distanceBetweenCustomerAndTaxi < min)
			{
				bookedTaxi = t;
				distanceBetweenPickUpandDrop = Math.abs((pickupPoint - '0') - (dropPoint - '0')) * 15;
				earning = (distanceBetweenPickUpandDrop-5) * 10 + 100;
				int dropTime = pickupTime + distanceBetweenPickUpandDrop/15;
				nextfreeTime = dropTime;
				nextSpot = dropPoint; 
				tripDetail = "      " + customerid + "               " + customerid + "          " + pickupPoint +  "      " + dropPoint + "       " + pickupTime + "          " +dropTime + "           " + earning;				
			}
		}
		bookedTaxi.setDetails(true, nextSpot, nextfreeTime, bookedTaxi.totalEarnings + earning, tripDetail);
		System.out.println("Taxi " + bookedTaxi.id + " booked");
	}
	public static void main(String[] args)
	{
		List<Taxi> taxis = createTaxis(4);
		Scanner sc = new Scanner(System.in);
		int id = 1;
		
		while(true)
		{
			System.out.println("---TAXI BOOKING CONSOLE-----");
			System.out.println("1. Book Taxi");
			System.out.println("2. Print Taxi Details");
			System.out.println("---------------------------------");
			System.out.print("Enter the choice: ");
			int choice = sc.nextInt();
			switch(choice)
			{
			case 1:
				int customerid = id;
				System.out.print("Enter Pickup Point: ");
				char pickupPoint = sc.next().charAt(0);
				System.out.print("Enter Drop Point: ");
				char dropPoint = sc.next().charAt(0);
				System.out.print("Enter pickup Time:");
				int pickupTime = sc.nextInt();
				if(pickupPoint < 'A' || pickupPoint > 'F' || dropPoint < 'A' || dropPoint > 'F')
				{
					System.out.println("Invalid pick up or drop point ~exited");
					return;
				}
				List<Taxi> freeTaxis = getFreeTaxis(taxis,pickupTime,pickupPoint);
				if(freeTaxis.size() == 0)
				{
					System.out.println("No Taxi can be allocated, Exiting");
					return;
				}
				Collections.sort(freeTaxis,(a,b)->a.totalEarnings - b.totalEarnings);
				bookTaxi(customerid,pickupPoint,dropPoint,pickupTime,freeTaxis);
				id++;
				break;
				
			case 2:
				for(Taxi t: taxis)
					t.printTaxiDetails();
				for(Taxi t: taxis)
					t.printDetails();
				break;
				
			default: 
				return;
			}
		}
	}
}
