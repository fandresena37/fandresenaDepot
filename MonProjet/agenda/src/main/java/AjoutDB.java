

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

import com.mysql.jdbc.PreparedStatement;

/**
 * Servlet implementation class AjoutDB
 */
public class AjoutDB extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public AjoutDB() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		response.getWriter().append("Served at: ").append(request.getContextPath());
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String dateEvent = request.getParameter("dateEvent");
		String Event = request.getParameter("Event");
		String description = request.getParameter("description");
		String proprietaire = request.getParameter("proprietaire");
		String dateCreate = request.getParameter("dateCreate");
		PrintWriter p = response.getWriter();
		try{// TODO Auto-generated method stub
			Class.forName("com.mysql.jdbc.Driver");
			Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/agenda?characterEncoding=UTF-8","fandresena","Azerty123!");
			String sql = "INSERT INTO "+proprietaire+" (date, event, description, proprietaire, date_de_creation) VALUES ('"+dateEvent+"', '"+Event+"', '"+description+"', '"+proprietaire+"', '"+dateCreate+"')";
			Statement st = con.createStatement();
			st.executeUpdate(sql);
//
//	        // Préparer la requête
//	        PreparedStatement statement = con.prepareStatement(sql);
//
//	        // Définir les valeurs des paramètres
//	        statement.setString(1, "20/04/2024");
//	        statement.setString(2, "test");
//	        statement.setString(3, "andrana");
//	        statement.setString(4, "fandresena");
//	        statement.setString(5, "date_de_creation");
////
////	        // Exécuter la requête
//	        statement.executeUpdate();
			//String cmd = "insert into "+proprietaire+" (date,event,description,proprietaire,date_de_creation) values("+dateEvent+","+Event+","+description+","+proprietaire+","+dateCreate+")";
			response.sendRedirect("http://localhost:8080/agenda/AjoutReu.jsp");
			}
			catch(Exception e) {
				response.sendRedirect("http://localhost:8080/agenda/AjouEu.jsp");
			}
//		<input type="text" name="dateEvent" placeholder="jj/mm/aa" class="input" value="<%=date%>">
//		<input type="password" name="Event" placeholder="l'evenement" class="input">
//		<input type="text" name="description" placeholder="description de l'evenement" class="input">
//		<input type="text" name="proprietaire" placeholder="proprietaire" class="input" value="${applicationScope.user}" readOnly>
//		<input type="text" name="dateCreate" placeholder="date de creation" class="input">
	}

}
