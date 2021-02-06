function josh(n)
{
    if (n == 1)
    {
        document.querySelector('#musician').innerHTML = "I have a degree in music from the University of North Texas.";
    }
    if (n == 2)
    {
        document.querySelector('#musician').innerHTML = "I have been playing percussion since 1992.";
    }
    if (n == 3)
    {
        document.querySelector('#musician').innerHTML = "I worked as a band director in Texas for many years.";
    }
    if (n == 4)
    {
        document.querySelector('#musician').innerHTML = "I played drumset for a living in NYC for several years.";
    }
}

function facts()
{
    var year = document.getElementById('year');
    var value = year.value;
    if (value == 1979)
    {
        document.getElementById('facts').innerHTML = "I was born.";
    }

    if (value == 2000)
    {
        document.getElementById('facts').innerHTML = "I played in Panorama in Trinidad.";
    }

    if (value == 2003)
    {
        document.getElementById('facts').innerHTML = "I graduated from The University of North Texas.";
    }

    if (value == 2007)
    {
        document.getElementById('facts').innerHTML = "I moved to Salvador, Brazil.";
    }

    if (value == 2012)
    {
        document.getElementById('facts').innerHTML = "I moved to NYC.";
    }

    if (value == 2019)
    {
        document.getElementById('facts').innerHTML = "I moved back to Texas to be a band director (again).";
    }

    if (value == "none")
    {
        document.getElementById('facts').innerHTML = "";
    }
}



