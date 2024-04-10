

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

/**
 * Servlet implementation class AfficheEvent
 */
public class AfficheEvent extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public AfficheEvent() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		PrintWriter p = response.getWriter();
		String user = request.getParameter("name");
		p.println("<html>"
				+ "<head>"
				+ "<meta charset=\"UTF-8\">"
				+ "<title>affichage</title>"
				+ "<link href=\"afficheCSS.css\" rel=\"stylesheet\"/>"
				+ "</head>");
		p.println("<body>");
		p.println("<table class=\"table-affiche\">"
				+ "<tr><td class=\"entete\">Date de l'evenement</td><td class=\"entete\">Evenement</td>"
				+ "<td class=\"entete\">Desciption</td><td class=\"entete\">Proprietaire</td><td class=\"entete\">Date d'ajout</td></tr>");
		try {
			Class.forName("com.mysql.jdbc.Driver");
			Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/agenda?characterEncoding=UTF-8","fandresena","Azerty123!");
			Statement st = con.createStatement();
			String query = "select *from "+user;
			ResultSet res = st.executeQuery(query);
			while(res.next()) {
				p.println("<tr><td>"+res.getString(1)+"</td><td>"+res.getString(2)+"</td><td>"+res.getString(3)+"</td>"
						+ "<td>"+res.getString(4)+"</td><td>"+res.getString(5)+"</td>");
			}
			
		}
		catch(Exception e) {
			
		}
		p.println("</table>"
				+ "</body>"
				+ "</html>");
		
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
