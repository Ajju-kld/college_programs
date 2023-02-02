class MultiplicationTableThread extends Thread
{
	private int n;

	public MultiplicationTableThread(int n)
	{
		this.n = n;
	}

	public void run()
	{
		for(int i=1;i<=10;i++)
		{
			System.out.println(n + " * " + i + " = " + n*i);
			try
			{
				sleep(1000);
			}
			catch(InterruptedException e)
			{

			}
		}
	}
}