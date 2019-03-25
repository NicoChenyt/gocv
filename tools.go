package gocv

//#include <stdlib.h>
//#include "tools.h"
import "C"

import (
	//"gocv"
)

func CoverWithTransparentImage(roi, cover Mat, scale float64) bool {
	return bool(C.CoverWithTransparentImage(roi.GetPtr(), cover.GetPtr(),  C.double(scale)))
}