#include <lclibrary/core/core.h>
#include <lclibrary/utils/utils.h>
#include <lclibrary/slc/rpp_3by2.h>
#include <cstring>
#include <sstream>

int main(int argc, char **argv) {

  if( argc != 4 ) {
    std::cerr << "Usage: " << argv[0] << " vertex_data required_edge_data nonrequired_edge_data" << std::endl;
    return 1;
  }

	std::stringstream vertex_data;
	std::stringstream required_edge_data;
	std::stringstream nonrequired_edge_data;

  vertex_data.str(argv[1]);
  required_edge_data.str(argv[2]);
  nonrequired_edge_data.str(argv[3]);

	std::shared_ptr <lclibrary::Graph> G;
	lclibrary::CreateGraph(G,
                         vertex_data,
                         required_edge_data,
                         nonrequired_edge_data,
                         false,
                         true);

	lclibrary::SLC_RPP slc_rpp(G);
	slc_rpp.Solve();
}

