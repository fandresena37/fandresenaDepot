

import jakarta.servlet.ServletException;
import jakarta.servlet.ServletResponse;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Calendar;

/**
 * Servlet implementation class genereAgenda
 */
public class genereAgenda extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public genereAgenda() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
//		response.getWriter().append("Served at: ").append(request.getContextPath());
		PrintWriter p =  response.getWriter();
		int mois;
		int annee;
		Calendar calendar = Calendar.getInstance();
		try {
			String Strmois = request.getParameter("mois"); 
			String Strannee  = request.getParameter("annee");
			mois = Integer.parseInt(Strmois);
			annee = Integer.parseInt(Strannee);
		}
		catch(Exception e) {
			mois = calendar.get(Calendar.MONTH); 
			annee = calendar.get(Calendar.YEAR);
		}
		// mois commence à 0
		calendar.set(Calendar.MONTH,mois);
		calendar.set(Calendar.YEAR, annee);// mois commence à 0
		int nbJours = calendar.getActualMaximum(Calendar.DAY_OF_MONTH);
		p.println("<html>"
				+ "<head>"
				+ "<meta charset=\"UTF-8\">"
				+ "<title>affichage</title>"
				+ "<link href=\"AffichageAge.css\" rel=\"stylesheet\"/>"
				+ "<script src=\"http://localhost:8080/agenda/script.js\"></script>"
				+ "</head>");
		p.println("<body>");
		p.println("<header>"
				+ "<div id=\"div\"><p id=\"mois\">mois:<span id=\"span\">"+getMois(mois+1)+"</span><button id=\"btn-mois\"onclick=\"changerMois()\">changer</button></p>"
				+ "</div><div id=\"id1\"><p id=\"annee\"><button id=\"btn-annee\"onclick=\"changerAnnee()\">changer</button>annee:<span id=\"span-annee\">"+annee+"</span></p></div>"
				+ "</header>"
				+ "<section style=\"height:88%;width:100%;display:flex;justify-content:center;align-items:center;background: linear-gradient(to right,blue,aqua);\">"
				+ "<section class=\"section\">");
		p.println("<section class=\"sec-agend\">");
		for (int i = 0; i < nbJours; i++) {
			calendar.set(annee, mois, i+1);
			p.println("<a id=\"ajout"+i+"\" class=\"lienAjout\" href=\"http://localhost:8080/agenda/Ajout.jsp?annee="+annee+"&mois="+(mois+1)+"&jour="+(i+1)+"\"/>"
					+ "<section class=\"jour\">"
					+ "<div class=\"day\">"
					+ "<h2>"+getJourSemaine(calendar.get(Calendar.DAY_OF_WEEK))+"</h2>"
					+ "</div>"
					+ "<div class=\"day-nb\">"
					+ "<p>"+(i+1)+"</p>"
					+ "</div>"
					+ "</section></a>");
		}
		p.println("</section></section></section></body>"
				+ "</html>");
	}
	private String getJourSemaine(int jourSemaine) {
        switch (jourSemaine) {
            case Calendar.SUNDAY:
                return "dimanche";
            case Calendar.MONDAY:
                return "lundi";
            case Calendar.TUESDAY:
                return "mardi";
            case Calendar.WEDNESDAY:
                return "mercredi";
            case Calendar.THURSDAY:
                return "jeudi";
            case Calendar.FRIDAY:
                return "vendredi";
            case Calendar.SATURDAY:
                return "samedi";
            default:
                return "samedi";
        }
	}
	private String getMois(int jourSemaine) {
        switch (jourSemaine) {
            case 1:
                return "Janvier";
            case 2:
                return "Fevrier";
            case 3:
                return "Mars";
            case 4:
                return "Avril";
            case 5:
                return "Mai";
            case 6:
                return "Juin";
            case 7:
                return "Juillet";
            case 8:
                return "Aôut";
            case 9:
                return "Septembre";
            case 10:
                return "Octobre";
            case 11:
                return "Novembre";
            case 12:
                return "Decembre";
            default:
                return "jour inconnu";
        }
	}
	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
