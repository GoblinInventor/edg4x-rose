
include_directories(${KDE4_INCLUDES} ${KDE4_INCLUDE_DIR} ${QT_INCLUDES} )

install(FILES Assert.h BitVector.h BitVectorSupport.h CommandLine.h DefaultAllocator.h Graph.h GraphBoost.h 
              IndexedList.h Interval.h IntervalMap.h IntervalSet.h Map.h Markup.h MarkupRoff.h
	      Message.h Optional.h PoolAllocator.h ProgressBar.h Sawyer.h SharedPointer.h WarningsOff.h WarningsRestore.h
        DESTINATION ${INCLUDE_INSTALL_DIR}/sawyer)
